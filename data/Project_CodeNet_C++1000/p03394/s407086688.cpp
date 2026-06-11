#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int N;
    cin >> N;
    int ans[] = {2, 5, 63, 20, 90};
    if (N < 6) {
        for (int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << endl;
    } else {
        int S = 0, k = 0, x0 = 0, x4 = 4;
        vector<int> ans;
        for (; N > 0; k++) {
            if (N) ans.push_back(6 * k + 2), N--, S += ans.back();
            if (N) ans.push_back(6 * k + 3), N--, S += ans.back();
            if (N) ans.push_back(6 * k + 4), N--, S += ans.back(), x4 = ans.back();
            if (N) ans.push_back(6 * k + 6), N--, S += ans.back(), x0 = ans.back();
        }
        if (S % 6 == 2) ans.erase(ans.begin()), ans.push_back(x0 + 6);
        if (S % 6 == 3) ans.erase(ans.begin() + 1), ans.push_back(x0 + 6);
        if (S % 6 == 5) ans.erase(ans.begin() + 1), ans.push_back(x4 + 6);
        for (const auto& x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}