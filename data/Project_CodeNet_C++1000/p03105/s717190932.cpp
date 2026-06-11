#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long int LL;
using namespace std;
int main()
{
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    if(A*C<=B)
        printf("%d\n",C);
    else
        printf("%d\n",(int)B/A);
    return 0;
}
