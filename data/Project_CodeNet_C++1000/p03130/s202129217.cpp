#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<int> a(3);
    vector<int> b(3);

    rep(i, 3) {
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> sum(4);
    for (int i = 0; i < 3; i++) {
        sum.at(a.at(i) - 1)++;
        sum.at(b.at(i) - 1)++;
    }

    string ans = "YES";
    for (int i = 0; i < 4; i++) {
        if (sum.at(i) == 1 || sum.at(i) == 2) {
            continue;
        }
        else {
            ans = "NO";
        }
    }
    cout << ans << endl;
}