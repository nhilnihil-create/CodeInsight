#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<ll, ll> P;

int n, k;
P p[100];

int main()
{
    cin >> n >> k;
    rep(i, n) cin >> p[i].first >> p[i].second;
    sort(p, p + n);

    ll res = 4 * 1e18;
    for(int left = 0; left < n - 1; left++)
    {
        for(int right = left + 1; right < n; right++)
        {
            while(p[right].first == p[right + 1].first)
            {
                right++;
            }
            vector<ll> y(0);
            for(int i = left; i <= right; i++)
            {
                y.emplace_back(p[i].second);
            }
            if(y.size() < k) continue;

            sort(y.begin(), y.end());
            int m = y.size();
            for(int l = 0; l < m - 1; l++)
            {
                for(int r = l + k - 1; r < m; r++)
                {
                    while(y[r] == y[r + 1])
                    {
                        r++;
                    }
                    ll ans = abs(p[right].first - p[left].first) * abs(y[r] - y[l]);
                    res = min(res, ans);
                }
            }
        }
    }
    cout << res << endl;
    
    return 0;
}