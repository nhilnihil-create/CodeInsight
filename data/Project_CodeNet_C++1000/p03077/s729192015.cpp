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
    ll n;
    cin >> n;

    vector<ll> a(5);
    rep(i, 5)cin >> a[i];
    sort(ALL(a));

    if(a[0] >= n){
        cout << 5 << endl;
        return 0;
    }

    ll ans = n / a[0] + 5;

    if(n % a[0] == 0)ans--;

    cout << ans << endl;
}