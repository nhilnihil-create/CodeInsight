#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    rep(i, n) {
        if (i == k - 1) {
            s[i] = tolower(s[i]);
        }
        cout << s[i];
    }
    cout << endl;
    return 0;
}