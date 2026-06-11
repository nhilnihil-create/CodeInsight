#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    a.emplace_back(-1);
    int ans = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) cnt++;
        else ans += cnt / 2, cnt = 1;
    }
    cout << ans << endl;
    return 0;
}
