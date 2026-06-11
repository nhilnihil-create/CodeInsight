#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> dp(n+2);
    vector<int> p(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    p[0] = 0;
    p[n+1] = n+1;

    for(int i = 1; i <= n+1; i++)
    {
        dp[i] = 1e14;
        ll bigger = 0;
        for(int j = i-1; j >= 0; j--)
        {
            if(p[i] > p[j])
            {
                dp[i] = min(dp[i], dp[j] + bigger * a + (i-j-1-bigger) * b);
            }
            else
            {
                bigger++;
            }
        }
    }
    cout << dp[n+1] << endl;
}
