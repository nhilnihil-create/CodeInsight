#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "!" + s + "!";
    vector<char> t(q), d(q);
    rep(i,q) cin >> t[i] >> d[i];
    int ok = 0, ng = n+1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        int cur = mid;
        rep(i,q){
            if(s[cur] == t[i]){
                if(d[i] == 'L') --cur;
                else ++cur;
            }
        }
        if(cur == 0) ok = mid;
        else ng = mid;
    }
    int ans = ok;
    ok = n+1, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        int cur = mid;
        rep(i,q){
            if(s[cur] == t[i]){
                if(d[i] == 'L') --cur;
                else ++cur;
            }
        }
        if(cur == n+1) ok = mid;
        else ng = mid;
    }
    ans += n + 1 - ok;
    ans = n - ans;
    cout << ans << endl;
    return 0;
}
