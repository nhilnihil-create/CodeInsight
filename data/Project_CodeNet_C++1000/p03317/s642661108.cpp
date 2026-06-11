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

    ll a[n];
    rep(i, n)cin >> a[i];

    rep(i, n){
        if(n <= (k-1)*i+1){
            cout << i << endl;
            return 0;
        }
    }
}