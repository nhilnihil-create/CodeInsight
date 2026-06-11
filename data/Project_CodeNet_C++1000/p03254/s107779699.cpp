#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    int ans = 0;
    rep(i, n - 1)
    {
        if (x >= a[i])
        {
            x -= a[i];
            ans++;
        }
        else
        {
            break;
        }
    }

    if (x == a[n - 1])
    {
        ans++;
    }

    cout << ans << endl;

    return 0;
}
