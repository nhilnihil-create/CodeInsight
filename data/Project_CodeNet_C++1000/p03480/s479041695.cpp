#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            ans = min(ans, max(i + 1, n - i - 1));
        }
    }
    cout << ans << endl;
}