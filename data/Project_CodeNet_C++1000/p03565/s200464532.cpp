#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s, t;
    cin >> s >> t;
    ll m = s.size();
    ll n = t.size();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    string ans = s;
    string res = s;
    bool clear = false;
    for (ll i=0; i<(m); i++){
        if (clear) break;
        for (ll j=0; j<(n); j++){
            if (i+j>=m){
                res = s;
                break;
            }
            if (res[i+j]!=t[j] && res[i+j]!='?'){
                res = s;
                break;
            }
            res[i+j] = t[j];
            if (j==n-1){
                clear = true;
                ans = res;
                break; break;
            }
        }
    }
    if (!clear){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    reverse(ans.begin(), ans.end());
    rep1(i, m) if (ans[i] == '?') ans[i] = 'a';
    cout << ans << endl;
    //printf("%.12f", ans);
}