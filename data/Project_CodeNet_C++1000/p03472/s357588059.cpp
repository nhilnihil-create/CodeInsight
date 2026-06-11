#include <bits/stdc++.h>
using namespace std;
//mayank srivastava
//d katana monster

int main()
{
    int n, h; cin >> n >> h;
    vector<int> a(n), b(n);
    int ma = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        ma = max(ma, a[i]);
    }
    int ans = 0;
    bool apurv = false;
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (ma < b[i]) 
        {
            ans++;
            h -= b[i];
        }
        if (h <= 0) 
        {
            apurv = true;
            break;
        }
    }
    if (!apurv)
    {
        ans += (h + ma - 1) / ma;
    }
    cout << ans << endl;
    return 0;
}