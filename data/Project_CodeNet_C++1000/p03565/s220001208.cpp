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
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    string s, t; cin >> s >> t;
    int n = sz(s);
    int m = sz(t);
    bool ok = false;
    rrep(i,n-m+1) {
        bool check = true;
        int cnt = 0;
        for (auto a : t) {
            if (a != s[i+cnt] && s[i+cnt] != '?') {
                check = false;
                break;
            }
            cnt++;
        }
        if (check) {
            cnt = 0;
            for (auto a : t) {
                s[i+cnt] = a;
                cnt++;
            }
            rep(i,n) {
                if (s[i] == '?') s[i] = 'a';
            }
            ok = true;
        }
    }
    if (!ok) cout << "UNRESTORABLE" << endl;
    else {
        rep(i,n) {
            cout << s[i];
        }
        cout << endl;
    }
}