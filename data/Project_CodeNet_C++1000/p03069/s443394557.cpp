#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int lb = 0;
    int rw = count(s.begin(), s.end(), '.');
    int ans = numeric_limits<int>::max();
    for (int i = 0; i <= n; i++) {
        ans = min(ans, lb + rw);
        if (i < n) {
            lb += s[i] == '#';
            rw -= s[i] == '.';
        }
    }
    cout << ans << '\n';
}
