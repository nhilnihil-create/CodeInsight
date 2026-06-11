#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    rep(i, n)
    {
        int t;
        cin >> t;
        a[t - 1]++;
    }

    sort(all(a));
    reverse(all(a));

    int res = 0;
    rep(i, k)
    {
        res += a[i];
    }
    cout << n - res << endl;
    return (0);
}
