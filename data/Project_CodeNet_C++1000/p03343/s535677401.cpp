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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    int mn = 1001001001;
    REP(i, n) {
        multiset<int> b;
        vector<int> c;
        REP(j, n) {
            if (a[j] < a[i]) {
                sort(ALL(c));
                REP(l, (int)c.size() - k + 1) b.insert(c[l]);
                c.clear();
            } else {
                c.push_back(a[j]);
            }
        }
        sort(ALL(c));
        REP(l, (int)c.size() - k + 1) b.insert(c[l]);
        if (b.size() >= q) {
            auto it = b.begin();
            REP(i, q - 1) it++;
            chmin(mn, *it - a[i]);
        }
    }

    cout << mn << endl;
}