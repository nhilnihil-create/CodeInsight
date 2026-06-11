#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int main()
{
    ll n; cin >> n;
    vector<pair<ll,pair<ll,ll> > > v;
    ll ans = 0;
    rep(i,n){
        ll x,y; cin >> x >> y;
        v.push_back(make_pair(x+y,make_pair(x,y)));
    }
    sort(v.begin(),v.end());
    
    rep(i,n){
        if(i % 2 == 0) ans += v[(n-1-i)].second.first;
        else ans -= v[n-1-i].second.second;
    }
    cout << ans << endl;
}