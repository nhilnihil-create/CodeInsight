#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

int main() {
    int n; cin >> n;
    vector<vector<char>> s(2 * n, vector<char>(2 * n));
    REP(i, n) {
        REP(j, n) {
            cin >> s[i][j];
            s[i][j + n] = s[i][j];
            s[i + n][j] = s[i][j];
            s[i + n][j + n] = s[i][j];
        }
    }
    ll ans = 0;
    REP(k, n) {
        bool b = false;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[j + k][i] != s[i + k][j]) {
                    b = true;
                }
            }
        }
        if (!b) {
            ans += n;
        }
    }
    cout << ans << endl;
    getchar(); getchar();
}