#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a = 0, b = 0, ba = 0, ans = 0;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size() - 1; i++)
            ans += (s[i] == 'A' && s[i + 1] == 'B');

        if (s[0] == 'B' && s.back() == 'A')
            ba++;
        else
            b += (s[0] == 'B'), a += (s.back() == 'A');
    }

    if (ba)
        ans += ba - 1 + (a > 0) + (b > 0), a--, b--;
    ans += max(0, min(a, b));

    cout << ans << '\n';
}
