#include <bits/stdc++.h>
 
using namespace std;

const int maxn = 2e5 + 20, mod = 1e9 + 7;
int n, a[maxn], dp[maxn], ii, i = -1;
pair <int, int> cs[maxn];

int main() 
{    
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < maxn; i++)
        cs[i].second = -1;

    for (int z = 0; z < n; z++)
    {
        i++;
        cin >> a[i];
        if (i > 0 && a[i] == a[i - 1])
        {
            i--;
            continue;
        }
        if (i > 0)
            dp[i] = dp[i - 1];
        if (cs[a[i]].second != -1)
            dp[i] = (dp[i] + dp[cs[a[i]].second])%mod;
        cs[a[i]].first++;
        cs[a[i]].second = i;
        ii =  i;
    }
    cout << dp[ii] << endl;
    return 0;    
}

