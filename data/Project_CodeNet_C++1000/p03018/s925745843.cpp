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
    string s;
    cin >> s;
    int l = s.size();
    string d = "";
    rep(i,l-1){
        if(s.substr(i,2)=="BC"){
            s[i+1]='D';
            continue;
        }
        d += s[i];
    }
    d += s[l-1];
    ll ans = 0;
    int d_l = d.size();
    int cnt = 0;
    rep(i,d_l){
        if(d[i]=='A'){
            cnt++;
        }
        else if(d[i]=='D'){
            ans += cnt;
        }
        else{
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
