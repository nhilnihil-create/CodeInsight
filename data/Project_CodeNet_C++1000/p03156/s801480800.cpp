#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    ll n;
    cin >> n;
    ll a,b;
    cin >> a >> b;
    vector<ll>p(n);
    ll one=0;
    ll two=0;
    ll thr=0;
    rep(i,n){
        cin >> p[i];
        if(p[i]<=a)one++;
        else if(p[i]<=b)two++;
        else thr++;
    }
    ll ans = min(one,min(two,thr));
    cout << ans << endl;
    return 0;
}
