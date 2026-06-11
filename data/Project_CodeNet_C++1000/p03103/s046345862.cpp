#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int n, M;
ll ans = 0, num = 0;
int main()
{
    cin >> n >> M;
    vector<pair<long long, long long>> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    for (auto v : a)
    {
        if (num >= M)
        {
            break;
        }
        else if (num + v.second <= M)
        {
            num += v.second;
            ans += v.first * v.second;
        }
        else
        {
            ans += v.first * (M - num);
            num = M;
        }
    }
    cout << ans << endl;
    return 0;
}