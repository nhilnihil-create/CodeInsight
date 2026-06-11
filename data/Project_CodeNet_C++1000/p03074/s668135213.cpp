#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(v) for (auto itr = v.begin(), itr != v.end(); ++itr)
#define LB(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define UB(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    string S;
    cin >> N >> K >> S;
    int res = 0;
    int l = 0, r = 0;
    while (r < N && S[r] == '1') {
        ++r;
        ++res;
    }
    queue<int> qu;
    while (r < N) {
        while (K) {
            while (r < N && S[r] == '0') ++r;
            --K;
            qu.emplace(r);
            while (r < N && S[r] == '1') ++r;
        }
        ++K;
        res = max(res, r - l);
        l = qu.front();
        qu.pop();
    }
    cout << res << endl;

    return 0;
}
