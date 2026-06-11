#include<bits/stdc++.h>
using namespace std;

int ans;
long long a,b;

int main()
{
    scanf("%lld%lld",&a,&b);
    while(a<=b) 
    {
        ++ans;
        a*=2;
    }
    printf("%d",ans);
    return 0;
}