#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, ara;

    scanf("%d %d", &a, &b);
    ara = a*b;
    ara = ara + 1;
    ara = ara - (a+b);

    printf("%d\n", ara);

    return 0;
}
