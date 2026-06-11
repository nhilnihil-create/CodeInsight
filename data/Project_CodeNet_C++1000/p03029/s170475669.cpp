#include <bits/stdc++.h>
int main ()
{
    int A,P,total_piece,max_pie;
    scanf ("%d %d",&A,&P);
    total_piece=(3*A)+P;
    max_pie=total_piece/2;
    printf ("%d\n",max_pie);
    return 0;
}
