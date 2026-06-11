#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, i;
    string s;
    cin >> n >> s;
    int black[n] = {0}, white[n] = {0};
    for (i = 0; i < n; i++) {
        if (s[i] == '#')
            black[i]++;
        else
            white[i]++;
        if (i != 0)
            black[i] += black[i - 1];
    }
    for (i = n - 2; i >= 0; i--)
        white[i] += white[i + 1];
    int ans = n;
    for (i = 0; i < n - 1; i++)
        ans = min(ans, black[i] + white[i + 1]);
    ans = min(ans, black[n - 1]);
    ans = min(ans, white[0]);
    cout << ans << endl;
}
