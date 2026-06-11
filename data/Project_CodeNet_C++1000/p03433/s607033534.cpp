#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

#define PY "Yes\n"    // printf(PY);
#define PN "No\n"     // printf(PN);

int main()
{
    int n, a;
    scanf("%d%d", &n, &a);

    if((n%500)<=a)
        printf(PY);
    else
        printf(PN);

    return 0;
}
