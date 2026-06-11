#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, sum;
    cin >> n;
    vector<int> up(n), bo(n);
    for (int i = 0; i < n; i++) cin >> up.at(i);
    for (int i = 0; i < n; i++) cin >> bo.at(i);
    sum = up.at(0);
    for (int i = 0; i < n; i++) sum += bo.at(i);
    ans = sum;
    for (int i = 0; i < n - 1; i++) {
        sum = sum - bo.at(i) + up.at(i + 1);
        ans = max(ans, sum);
    }
    cout << ans << endl;
}