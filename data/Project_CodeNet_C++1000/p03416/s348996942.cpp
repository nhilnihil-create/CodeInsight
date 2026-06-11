#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

bool is_palindrome(int x)
{
    int tmp = x;
    int res = 0;
    if (x != 0 && x % 10 == 0)
    {
        return 0;
    }
    while (res < x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return x == res || x == res / 10;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 0;
    rep2(i, a, b + 1) ans += is_palindrome(i);

    cout << ans << endl;

    return 0;
}
