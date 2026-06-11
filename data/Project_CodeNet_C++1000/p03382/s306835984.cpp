#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    int ans1 = a[n - 1];
    int ans2 = a[n - 1];
    int f = INT_MAX;
    rep(i, n - 1)
    {
        if (f >= abs(a[n - 1] / 2 - a[i]))
        {
            ans2 = a[i];
            f = abs(a[n - 1] / 2 - a[i]);
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}