#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(m >= a[i].second)
        {
            ans += a[i].second * a[i].first;
            m -= a[i].second;
        }
        else
        {
            ans += m * a[i].first;
            m = 0;
            break;
        }
    }

    cout << ans;

    return 0;
}
