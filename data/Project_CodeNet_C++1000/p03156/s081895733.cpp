#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0;
    int y = 0;
    int z = 0;
    int p;
    REP(i, n) {
        cin >> p;
        if (p <= a) {
            x++;
        } else if (p <= b) {
            y++;
        } else {
            z++;
        }
    }
    cout << min({x, y , z}) << endl;
}
