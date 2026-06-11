#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int sum_digit(int a, int b)
{
    int res = 0;
    while (a || b)
    {
        res += a % 10 + b % 10;
        a /= 10;
        b /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int ans = 1001001001;

    for (int a = 1; a < n; a++)
    {
        int b = n - a;
        ans = min(sum_digit(a, b), ans);
    }

    cout << ans << endl;

    return 0;
}
