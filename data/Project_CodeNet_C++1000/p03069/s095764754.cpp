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
    string s;
    cin >> s;
    vector<ll>l(n+1,0);
    vector<ll>r(n+1,0);
    for(int i=1;i<n;i++){
        l[i]=l[i-1];
        if(s[i-1]=='#'){
            l[i]++;
        }
    }
    for(int i=n-1;i>=0;i--){
        r[i]=r[i+1];
        if(s[i+1]=='.'){
            r[i]++;
        }
    }
    ll ans = INF;
    rep(i,n){
        chmin(ans,l[i]+r[i]);
    }
    cout << ans << endl;
    return 0;
}
