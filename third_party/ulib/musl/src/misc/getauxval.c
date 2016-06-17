#include "libc.h"
#include <errno.h>
#include <sys/auxv.h>

unsigned long getauxval(unsigned long item) {
    size_t* auxv = libc.auxv;
    if (item == AT_SECURE) return libc.secure;
    for (; *auxv; auxv += 2)
        if (*auxv == item) return auxv[1];
    errno = ENOENT;
    return 0;
}