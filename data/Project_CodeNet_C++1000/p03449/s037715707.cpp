#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a1(n);
    for (int i = 0; i < n; i++) {
        cin >> a1.at(i);
    }
    vector<int> a2(n);
    for (int i = 0; i < n; i++) {
        cin >> a2.at(i);
    }

    vector<int> a1sum(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            a1sum.at(i) = a1.at(i);
        } else {
            a1sum.at(i) = a1sum.at(i-1) + a1.at(i);
        }
    }
    vector<int> a2sum(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            a2sum.at(i) = a2.at(i);
        } else {
            a2sum.at(i) = a2sum.at(i-1) + a2.at(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans = a1sum.at(i) + a2sum.at(n-1);
        } else {
            ans = max(ans, a1sum.at(i) + a2sum.at(n-1) - a2sum.at(i-1));
        }
    }

    cout << ans << endl;
}