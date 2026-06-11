#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> d(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        d[i] = d[i - 1] + (s[i - 1] == '.');
    }
    int ans = 1001001001;
    for (int i = 0; i < n + 1; ++i) {
        ans = min(ans, (i - d[i]) + (d[n] - d[i]));
    }
    cout << ans << endl;
}
