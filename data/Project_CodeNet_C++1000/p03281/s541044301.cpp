// https://atcoder.jp/contests/abc106/tasks/abc106_b
#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int_fast32_t i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int_fast32_t i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

vector<int> a = {105, 135, 165, 189, 195};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    if (N >= 195) {
        cout << "5\n";
    } else if (N >= 189) {
        cout << "4\n";
    } else if (N >= 165) {
        cout << "3\n";
    } else if (N >= 135) {
        cout << "2\n";
    } else if (N >= 105) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
