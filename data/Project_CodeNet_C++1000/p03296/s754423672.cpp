#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int ans = 0;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a.at(i) == a.at(i + 1)) cnt++;
        else {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    ans += cnt / 2;
    cout << ans << endl;
}