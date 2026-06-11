#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int x;
    cin >> x;

    int ans = 1;
    for (int i = 2; i * i <= x; i++)
    {
        int res = i;
        while (res * i <= x)
        {
            res *= i;
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
    return (0);
}
