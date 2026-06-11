#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int f(int n)
{
    return ((n % 2 == 0) ? n / 2 : 3 * n + 1);
}

int main()
{
    string s;
    cin >> s;

    int ans = 1001001001;
    rep(i, s.size() - 2)
    {
        int cnt = 0;
        rep(k, 3) cnt = cnt * 10 + s[i + k] - '0';
        ans = min(ans, abs(753 - cnt));
    }

    cout << ans << '\n';
    return 0;
}
