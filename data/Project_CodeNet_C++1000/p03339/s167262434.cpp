#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> left(n);
    if (s[0] == 'W') left[0] = 1;
    for (int i = 1; i < n; ++i) left[i] = s[i] == 'W' ? left[i - 1] + 1 : left[i - 1];
    vector<int> right(n);
    if (s[n - 1] == 'E') right[0] = 1;
    for (int j = 1; j < n; ++j) right[j] = s[n - j - 1] == 'E' ? right[j - 1] + 1 : right[j - 1];
    int ans = 1001001001;
    for (int k = 0; k < n; ++k) {
        int cnt = 0;
        if (k != 0) cnt += left[k - 1];
        if (k != n - 1) cnt += right[n - k - 1];
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}
