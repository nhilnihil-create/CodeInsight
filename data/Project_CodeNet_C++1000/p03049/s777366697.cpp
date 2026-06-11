#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if (s.front() == 'B' && s.back() == 'A') z++;
        else if (s.front() == 'B') x++;
        else if (s.back() == 'A') y++;
        
        rep(j, sz(s) - 1) {
            if (s[j] == 'A' && s[j+1] == 'B') ans++;
        }
    }
    if (x == 0 && y == 0 && z > 0) {
        ans += z-1;
    } else {
        ans += min(x+z, y+z);
    }
    cout << ans << endl;
}