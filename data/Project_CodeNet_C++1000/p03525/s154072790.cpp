#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n;   cin >> n;
    map<ll, ll> mp;
    vector<ll> v, tar;
    mp[0] += 1;
    rep(i, n){
        ll x;   cin >> x;
        mp[x] += 1;
    }
    ll res=-1;
    tar.push_back(0);
    tar.push_back(24);
    for(auto x: mp){
        if(!(x.first%12) && 1<x.second) res = 0;
        else if(2<x.second) res = 0;
        else if(2==x.second){
            tar.push_back(x.first);
            tar.push_back(24-x.first);
        }else if(0<x.first) v.push_back(x.first);
            
    }
    
    if(res<0){
        ll sv=v.size();
        rep(i, 1<<sv){ 
            vector<ll> tmp = tar;
            rep(j, sv){
                if(i&1<<j) tmp.push_back(v[j]);
                else tmp.push_back(24-v[j]);
            }
            sort(ALL(tmp));
            ll uiw=LINF;
            rep(i, tmp.size()-1) uiw = min(uiw, tmp[i+1]-tmp[i]);
            res = max(res, uiw);
        }
    }
    cout << res << endl;
}
