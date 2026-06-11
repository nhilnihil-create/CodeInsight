#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<ll,pair<ll,ll>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main(){
    ll h, w, n;
    cin >> h >> w >> n;
    vector<pair<ll, ll>> p(n);
    vector<ll> l(h, 1);
    rep(i, n)cin >> p[i].first >> p[i].second;
    sort(all(p));
    REP(i, h-1){
        l[i] = l[i-1];
        if(!binary_search(all(p), make_pair((ll)i+1, l[i]+1)))l[i]++;
    }
    ll ans = h;
    rep(i, n){
        if(p[i].second <= l[p[i].first-1]){
            chmin(ans, p[i].first-1);
        }
    }
    cout << ans << endl;
}