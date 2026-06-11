#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, sum;
    cin >> n;
    vector<int> up(n), bo(n);
    for (int i = 0; i < n; i++) cin >> up.at(i);
    for (int i = 0; i < n; i++) cin >> bo.at(i);
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j <= i; j++) sum += up.at(j);
        for (int j = i; j < n; j++) sum += bo.at(j);
        ans = max(ans, sum);
    }
    cout << ans << endl;
}