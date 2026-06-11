#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+5;
const int maxm=5e2+5;
const int maxq=55;
const int INF=0x3f3f3f3f;
int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        if(n%2==0)
            printf("%lld\n",n);
        else
            printf("%lld\n",n*2);
    }
}
