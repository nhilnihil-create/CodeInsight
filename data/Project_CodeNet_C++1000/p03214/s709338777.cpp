#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, sum = 0, ans;
    double ave = 0, d = INT_MAX;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    ave = (double)sum / n;
    rep(i, n)
    {
        if (d > abs(a[i] - ave))
        {
            ans = i;
            d = abs(a[i] - ave);
        }
    }
    cout << ans << endl;
    return 0;
}
