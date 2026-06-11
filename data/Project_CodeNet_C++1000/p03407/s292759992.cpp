#include<bits/stdc++.h>
using namespace std;

int a,b,c;

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>=c)
    {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    return 0;
}