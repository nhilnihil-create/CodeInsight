#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
#define int long long
typedef long long ll;
using namespace std;

int solve(const string& s) {
    int n = sz(s);
    int ans = 0, cnt = 0;
    rrep(i, 1, n) {
        char c = s[i - 1];
        if(c == 'A') {
            ans += cnt;
        } else if(c == 'B') {
            cnt++;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if(sz(s) < 3) {
        cout << 0 << endl;
        return 0;
    }
    if(s[sz(s) - 1] == 'B') {
        s = s.substr(0, sz(s) - 1);
    } else if(s[sz(s) - 1] == 'C' && s[sz(s) - 2] != 'B') {
        s = s.substr(0, sz(s) - 2);
    }
    string t;
    int n = sz(s), ans = 0;
    rep(i, 1, n - 1) {
        char c = s[i - 1], cc = s[i];
        if(c == 'A') {
            t += c;
        } else if(c == 'B') {
            if(cc == 'C') {
                t += "BC";
                i++;
            } else {
                ans += solve(t);
                t = "";
            }
        } else if(c == 'C') {
            ans += solve(t);
            t = "";
        }
    }
    ans += solve(t);
    cout << ans << endl;
    return 0;
}
