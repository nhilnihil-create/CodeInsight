#include<iostream>

using namespace std;
const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=1;i<=n;++i){
        ll r = n/(n/i);
        ll t = n/i;
        if(n%t==0){
            ll x = n/t - 1;
            if(x>=i && x<=r) ans += x;
        }
        i = r;
    }
    cout << ans << endl;
    return 0;
}
