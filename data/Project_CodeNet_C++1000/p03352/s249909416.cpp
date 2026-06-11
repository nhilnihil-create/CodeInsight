#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int x;
    cin >> x;

    set<int> nums;
    for (int b = 1; b <= 32; b++) {
        for (int p = 2; p <= 10; p++) {
            int ex = pow(b, p);
            if (0 <= ex && ex <= 1000)
                nums.insert(ex);
        };
    }

    vector<int> exp;
    for (auto num : nums) exp.push_back(num);
    sort(exp.begin(), exp.end());

    rep(i, exp.size()) {
        if (exp.at(i) == x) {
            cout << exp.at(i) << endl;
            return 0;
        } else if (exp.at(i) > x) {
            cout << exp.at(i - 1) << endl;
            return 0;
        }
    }
}
