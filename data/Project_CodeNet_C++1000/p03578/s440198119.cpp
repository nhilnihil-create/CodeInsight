#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

int main() {
    int n;
    cin >> n;

    // vector<int> diff(n);
    map<int, int> diffCnt;
    rep(i, 0, n) {
        int idx;
        cin >> idx;
        diffCnt[idx]++;
    }

    int m;
    cin >> m;

    rep(i, 0, m) {
        int idx;
        cin >> idx;
        diffCnt[idx]--;
        if (diffCnt[idx] < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
