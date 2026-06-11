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
    int n;
    cin >> n;
    vector<int> a(n);
    int t = 0;
    REP(i, n) {
        cin >> a[i];
        t += a[i];
    }
    double ave = (double)t / n;
    double d = 100100.0;
    int r = -1;
    REP(i, n) {
        if (d > abs(ave - a[i])) {
            d = abs(ave - a[i]);
            r = i;
        }
    }

    cout << r << endl;
}
