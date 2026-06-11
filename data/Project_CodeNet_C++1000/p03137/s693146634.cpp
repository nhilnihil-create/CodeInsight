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
    ll n, m;
    cin >> n >> m;

    vector<ll> x(m);
    rep(i, m)cin >> x[i];
    sort(ALL(x));

    if(n >= m){
        cout << 0;
        return 0;
    }

    vector<ll> dif(m-1);
    ll sum = 0;
    rep(i, m-1){
        dif[i] = abs(x[i+1] - x[i]);
        sum += dif[i];
    }
    sort(ALL(dif), greater<ll>());

    sum -= accumulate(dif.begin(), dif.begin()+(n-1), 0);
    
    cout << sum << endl;
}