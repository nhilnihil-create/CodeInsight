#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 2e5 + 5;

int n, h[maxn], a[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    h[0] = 0; a[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> dp;
    for(int i = n; i >= 0; i--)
    {
        auto it = dp.upper_bound(h[i]);
        int sum = a[i];
        if(it != dp.end())
            sum += it -> second;
        dp[h[i]] = sum;
        it = dp.find(h[i]);
        while(it != dp.begin() && prev(it) -> second <= sum)
            it = dp.erase(prev(it));
    }
    cout << dp[0] << "\n";
    return 0;
}