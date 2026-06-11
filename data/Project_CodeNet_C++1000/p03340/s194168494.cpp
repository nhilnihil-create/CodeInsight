#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+5;
const int INF = 1e9+7;
#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F first
#define S second

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll MOD(ll a){
    return ((a%INF)+INF)%INF;
}

ll inv(ll a){
    return poww(a,INF-2,INF);
}

ll a[MAXN],sums[MAXN],xorr[MAXN];

int main()
{
    fast_io;
    //cout << fixed << setprecision(15);

    ll n;cin >> n;
    for(ll i=1;i<=n;++i) cin >> a[i];
    for(ll i=1;i<=n;++i) sums[i] = sums[i-1] + a[i],xorr[i] = xorr[i-1] ^ a[i];
    ll res=0;
    for(ll i=1;i<=n;++i){
        ll l = 0,r = i;
        while(r-l > 1){
            ll mid = l + (r-l) / 2;
            if(sums[i] - sums[mid-1] == (xorr[i] ^ xorr[mid-1])) r = mid;
            else l=mid;
        }
        res += i - r +1;
    }
    cout << res;
}

