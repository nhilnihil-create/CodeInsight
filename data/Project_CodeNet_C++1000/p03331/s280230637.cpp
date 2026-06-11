#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int wa(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}

int main()
{
    int n;
    cin >> n;

    int ans = 1001001001;
    rep2(a, 1, n)
    {
        int b = n - a;
        ans = min(ans, wa(a) + wa(b));
    }

    cout << ans << endl;

    return 0;
}
