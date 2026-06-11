#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;

    int idx = 0;
    while(x > 0 && idx < n)
    {
        if (x >= a[idx])
        {
            ans++;
            x -= a[idx];
        }
        else
        {
            break;
        }
        idx++;
    }
    if (x != 0 && idx == n && ans != 0) ans--;
    cout << ans << endl;
    
    return 0;
}
