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

    map<int, int> cnt;
    rep(i, 0, n) {
        int val;
        cin >> val;
        cnt[val]++;
    }
    int ans = 0;
    for (auto val : cnt) {
        if (val.first > val.second) {
            ans += val.second;
        } else if (val.first < val.second) {
            ans += val.second - val.first;
        }
    }
    cout << ans << endl;
    return 0;
}
