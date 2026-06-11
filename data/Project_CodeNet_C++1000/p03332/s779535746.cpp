#include <bits/stdc++.h>
#define Phuong ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
using namespace std;
const ll modprime = 998244353;
const int MAXN = 3*1e5+2;
ll fact[MAXN];

ll n,a,b;

ll numA, numB, k;

void init()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=MAXN-2; ++i)
    {
        fact[i]=(i*fact[i-1])%modprime;
    }
}

ll lt(ll x)
{
    if (x==1) return 1;
    ll res=1;
    int y =modprime -2;
    while (y>0)
    {
        if (y&1) res=(res*x)%modprime;
        y=y>>1;
        x=(x*x)%modprime;
    }
    return res;
}

ll compute(ll x, ll y)
{
    if (y>=x) return 1;
    if (y==0) return 1;
    ll inv1=lt(fact[y]);


    ll inv2=lt(fact[x-y]);
    ll ans = (fact[x]*inv1)%modprime;
    ans=(ans*inv2)%modprime;

    return (ans);

}

int main()
{
    Phuong;
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n >> a >> b >> k;
    ll sum=0;
    for(int i=0; i<=n; ++i)
    {
        numA= i;
        numB= k-i*a;
        if (numB<0) continue;
        if (numB%b!=0) continue;
        numB/=b;
        if (numB>n) continue;
        ll ansA= compute(n,numA);
        ll ansB= compute(n,numB);

        sum+= (ansA*ansB)%modprime;
        sum%=modprime;
    }
    cout << sum;
    return 0;
}
