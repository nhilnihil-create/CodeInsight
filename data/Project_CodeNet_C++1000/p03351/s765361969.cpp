#include<bits/stdc++.h>
#define LL long long
#define inf 0x3fffffffffffffff
using namespace std;

int a,b,c,d;

bool check(int x,int y)
{
    return abs(x-y)<=d;
}

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (check(a,c)||check(a,b)&&check(b,c)) puts("Yes");
    else puts("No");
    return 0;
}