#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1e9+7
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h)rep(j,w) {
        if (s[i][j] == '#') continue;
        int cnt = 0;
        for (int k=-1; k<=1; k++) {
            if (i+k<0 || i+k>h-1) continue;
            for (int l=-1; l<=1; l++) {
                if (j+l<0 || j+l>w-1) continue;
                if (s[i+k][j+l] == '#') cnt++;
            }
        }
        s[i][j] = '0' + cnt;
    }
    rep(i,h)rep(j,w) {
        cout << s[i][j];
        if (j == w-1) cout << endl;
    }
} 