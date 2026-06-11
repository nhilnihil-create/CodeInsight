#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//入力
ll n;
vector<ll>a;

int main(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin>>a[i];
    a.push_back(0);
    bool ok = true;
    if(a[0]!=0)ok=false;
    rep(i,n-1){
        if(a[i+1]-a[i]>=2)ok=false;
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    rep(i,n){
        if(a[i+1]!=a[i]+1){
            ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
