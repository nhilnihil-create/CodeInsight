#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int ans = 0;
    int a = 0, b = 0, ab = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s.front() == 'B' && s.back() == 'A') ab++;
        else if (s.front() == 'B') b++;
        else if (s.back() == 'A') a++;

        int len = s.length();
        for (int j = 0; j < len - 1; j++) {
            if (s[j] == 'A' && s[j + 1] == 'B') ans++;
        }
    }

    if (ab > 0) {
        ans += ab - 1;
        if (a > 0) a--, ans++;
        if (b > 0) b--, ans++;
    }
    ans += min(a, b);
    cout << ans << endl;
    return 0;
}