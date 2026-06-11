#include <stdio.h>
#include <string.h>
#include <math.h>
int main ()
{
    int n, a, b;
    scanf ("%d %d %d", &n, &a, &b);
    if ((a+b)%2==0) printf ("Alice");
    else printf ("Borys");
    return 0;
}
