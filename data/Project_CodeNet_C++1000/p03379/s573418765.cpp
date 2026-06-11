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

    vector<int> inp(n);
    int centerIdx = n / 2 - 1;
    // n
    rep(i, 0, n) {
        cin >> inp[i];
    }

    vector<int> vec;
    // n
    copy(inp.begin(), inp.end(), back_inserter(vec));
    sort(vec.begin(), vec.end());
    int centerVal = vec[centerIdx];
    rep(i, 0, n) {
        if (inp[i] > centerVal) {
            cout << centerVal << endl;
            // } else if (inp[i] == centerVal) {
            // do
        } else {
            cout << vec[centerIdx + 1] << endl;
        }
    }

    return 0;
}
