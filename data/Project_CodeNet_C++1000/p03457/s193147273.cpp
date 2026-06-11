#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n + 1), x(n + 1), y(n + 1);
    t[0] = 0;
    pair<int ,int> p(0, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = t[i - 1]; j < t[i]; j++) {
            if (p.first < x[i]) ++p.first;
            else if (p.first > x[i]) --p.first;
            else if (p.second < y[i]) ++p.second;
            else if (p.second > y[i]) --p.second;
            else if (p.first == x[i] && p.second == y[i]) --p.first;
        }
        if (p.first == x[i] && p.second == y[i]) continue;
        else {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}