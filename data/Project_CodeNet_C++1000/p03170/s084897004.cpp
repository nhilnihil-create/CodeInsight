#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

vector<int> v(105);
vector<bool> dp(100005, false);

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++)
            if(i-v[j] >= 0 && !dp[i-v[j]])
                dp[i] = true;
    cout << (dp[k] ? "First" : "Second") << endl;
}