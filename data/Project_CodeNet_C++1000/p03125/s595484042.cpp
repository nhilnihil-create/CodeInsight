#include <stdio.h>

int main() {
    int aa, bb, cc, dd;
    scanf("%d %d", &aa, &bb);
    cc = aa + bb;
    dd = bb - aa;
    bb % aa == 0 ? printf("%d", cc) : printf("%d", dd);


    return 0;
}