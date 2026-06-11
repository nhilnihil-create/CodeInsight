#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    if ((b - a) / 2 < k)
        rep2(i, a, b + 1) cout << i << '\n';
    else
    {
        rep2(i, a, a + k) cout << i << '\n';
        rep2(i, b + 1 - k, b + 1) cout << i << '\n';
    }
    return 0;
}
