#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int digit_sum(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return (res);
}

int main()
{
    int n;
    cin >> n;

    int ans = 1001001001;
    rep2(a, 1, n)
    {
        int b = n - a;
        int tmp = digit_sum(a) + digit_sum(b);
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return (0);
}
