#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int r;

    scanf("%d", &r);

    if( r < 1200 ) puts("ABC");
    else if( 1200 <= r && r < 2800 ) puts("ARC");
    else puts("AGC");

    return 0;
}