#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

#define PI 3.141592
int main() {
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> pos(m);
    // O:m
    rep(i, 0, m) {
        cin >> pos[i];
    }

    // O;mlog(m)
    sort(pos.begin(), pos.end());

    vector<int> lenList(m - 1);
    // O:m-1
    rep(i, 0, m - 1) {
        lenList[i] = abs(pos[i] - pos[i + 1]);
    }

    // O:mlog(m)
    sort(lenList.begin(), lenList.end());

    // O:m-1
    long sum = 0;
    rep(i, 0, lenList.size() - (n - 1)) {
        sum += lenList[i];
    }

    cout << sum << endl;

    return 0;
}
