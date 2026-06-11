#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<string, string> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    map<P, ll> mp;
    rep(bit,(1<<n)){
        string t = "", u = "";
        rep(i,n){
            if(bit>>i & 1) t += s[i];
            else u += s[i];
        }
        reverse(u.begin(), u.end());
        mp[P(t, u)]++;
    }
    ll ans = 0;
    rep(bit,(1<<n)){
        string t = "", u = "";
        for(int i = n; i < n*2; ++i){
            if(bit & (1<<(i - n))) t += s[i];
            else u += s[i];
        }
        reverse(u.begin(), u.end());
        ans += mp[P(u, t)];
    }
    cout << ans << endl;
    return 0;
}