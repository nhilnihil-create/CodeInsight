#include <stdio.h>

int main()
{
    int A, P;
    int slice = 0, pie = 0;

    scanf("%d %d", &A, &P);

    while (A>0){
        slice += 3;
        A--;
    }

    slice += P;

    while (slice >= 2){
        slice -= 2;
        pie++;
    }

    printf("%d", pie);

    return 0;
}
