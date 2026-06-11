#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    REP(i, n) {
        cin >> a[i];
    }

    int t = 0;
    REP(k, n) {
        bool ok = true;
        REP(i, n) {
            FOR(j, i, n) {
                if (a[i][j] != a[j][i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            t++;
        }
        vector<string> b;
        REP1(i, n - 1) {
            b.push_back(a[i]);
        }
        b.push_back(a[0]);
        b.swap(a);
    }

    cout << t * n << endl;
}
