#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int twice(int x, int k)
{
    if (!k)
        return x;
    return twice(2 * x, k - 1);
}

int main()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ans = twice(max({a, b, c}), k);
    cout << ans + a + b + c - max({a, b, c}) << '\n';
    return (0);
}
