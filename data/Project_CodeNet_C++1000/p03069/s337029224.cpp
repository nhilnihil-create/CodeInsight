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
    string S;
    cin >> N >> S;
    int left = 0;
    while (left < N) {
        if (S[left] == '#') break;
        ++left;
    }
    int right = N - 1;
    while (right >= 0) {
        if (S[right] == '.') break;
        --right;
    }
    int white = 0;
    FOR(i, left, right + 1) {
        white += (S[i] == '.');
    }
    int i = left;
    int res = white;
    int black = 0;
    while (i < right + 1) {
        while (i < right + 1 && S[i] == '#') {
            ++black;
            ++i;
        }
        while (i < right + 1 && S[i] == '.') {
            --white;
            ++i;
        }
        res = min(res, black + white);
    }
    cout << res << endl;

    return 0;
}
