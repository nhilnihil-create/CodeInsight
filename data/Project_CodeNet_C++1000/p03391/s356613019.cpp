#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define ci cin
#define co cout
#define ed endl
#define vc vector
#define sr string
#define pb push_back
#define st(a,n) sort(a,a+n)
#define ms(a) memset(a,0,sizeof(a))
#define fr(i,k,n) for(int i=k;i<=n;++i)
#define FR(i,n,k) for(int i=n;i>=k;--i)
#define inf 0x3f3f3f3f
#define exp 1e-6
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int mod =1e9+7;
const int maxn = 2e5+10;
int main()
{
    int n;
    scanf("%d",&n);
    ll ans=0,mx=1000000010;
    int flag=1;
    while(n--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(a!=b) flag=0;
        ans+=a;
        if(a>b) mx=min(mx,b);
    }
    if(flag) co<<0<<ed;
    else co<<ans-mx<<ed;
    return 0;
}
