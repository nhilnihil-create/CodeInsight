#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    bool flag = true;
    rep(i, n - 1) if (s[i + 1] != '9') {
        flag = false;
        break;
    }

    if (flag)
        cout << s[0] - '0' + 9 * (n - 1);
    else
        cout << s[0] - '0' + 9 * (n - 1) - 1;
    cout << endl;

    return 0;
}