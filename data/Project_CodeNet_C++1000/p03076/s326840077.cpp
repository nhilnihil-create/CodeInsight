#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        cin >> a.at(i);
    }
    vector<int> ma(5);
    transform(a.begin(), a.end(), ma.begin(), [](double x) { return ceil(x / 10) * 10; });
    int sum = accumulate(ma.begin(), ma.end(), 0);
    int ans = 1e9;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, sum - ma.at(i) + a.at(i));
    }
    cout << ans << endl;
    return 0;
}