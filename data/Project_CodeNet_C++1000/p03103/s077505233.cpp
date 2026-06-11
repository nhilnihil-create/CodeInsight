#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n);
    for (size_t i = 0; i < n; i++)
    {
        int b, c;
        cin >> b >> c;
        a[i] = {b, c};
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int bought = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (bought + a[i].second >= m)
        {
            ans += a[i].first * (m - bought);
            break;
        }
        else
        {
            ans += a[i].first * a[i].second;
            bought += a[i].second;
        }
    }
    cout << ans << endl;

    return 0;
}