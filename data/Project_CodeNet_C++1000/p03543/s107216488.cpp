#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int cnt = 0;
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (s[1] == s[2] && s[2] == s[3]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}