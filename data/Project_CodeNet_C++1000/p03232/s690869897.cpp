#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
ll n;
const ll N = 1e5 + 10;
ll p[N];
const ll mod = 1e9 + 7;
ll ME(ll x,ll nn,ll M)
{
    ll result=1;
    while(nn>0)
    {
        if(nn % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        nn=nn/2;
    }
    return result;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> n;
        p[1] = 1;
        ll ff=1LL;
        for(ll i=2;i<=n;i++) {
                p[i] = ME(i,mod-2,mod);
                ff = (ff * i)%mod;
                p[i] += p[i-1];
                p[i] %= mod;
        }
        ll ans = 0;
        for(ll i=1;i<=n;i++) {
                ll x;
                cin >> x;
                ll ret = 0;
                ret = (ret + p[i])%mod;
                ret = (ret + mod - 1 + p[n-i+1])%mod;
                ret %= mod;
                ret = (ret * x)%mod;
                ans = (ans + ret)%mod;
        }
        cout << (ans*ff)%mod << endl;
        return 0;
}
