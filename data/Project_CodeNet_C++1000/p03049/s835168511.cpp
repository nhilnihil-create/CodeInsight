#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> S(N);
    int res = 0;
    int front = 0, back = 0, front_back = 0;
    REP(i, N) {
        cin >> S[i];
        REP(j, S[i].size() - 1) {
            res += S[i].substr(j, 2) == "AB";
        }
        if (S[i].front() == 'B') {
            if (S[i].back() == 'A') {
                ++front_back;
            } else {
                ++front;
            }
        } else if (S[i].back() == 'A') {
            ++back;
        }
    }
    if (front_back > 0) {
        if (front + back == 0) {
            res += front_back - 1;
        } else {
            res += front_back + min(front, back);
        }
    } else {
        res += min(front, back);
    }
    cout << res << endl;

    return 0;
}
