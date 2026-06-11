#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    vector<int> num(n + 1, 0);
    for (int i = 0; i < n; i++) {
        num.at(a.at(i))++;
    }

    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());

    int ans = 0;
    int c = 0;
    while (num.at(c) != 0) {
        if (c >= k) {
            ans += num.at(c);
        }
        c++;
    }

    cout << ans << endl;
}