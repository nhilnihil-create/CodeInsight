#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    ll base = 1e12;
    
    for(ll i = 1; i <=n; ++i){
        ll res = base;

        for(ll j = i; j < k; j*=2)res /= 2;

        ans += res; 
    }
    printf("%.10f", double(ans)/double(n)/double(base));
}