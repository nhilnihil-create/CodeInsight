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
    
    vector<ll> a(n);
    ll cnt = 0;
    ll sum = 0;
    ll low = INF;
    rep(i, n){
        ll a;
        cin >> a;
        if(a < 0){
            cnt++;
            a *= -1;
        }
        sum += a;
        low = min(low, a);
    }

    if(cnt&1)sum -= 2*low;
    
    cout << sum << endl;
}