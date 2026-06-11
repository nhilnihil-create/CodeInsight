#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
const ll INTF = 1e9 + 7;

vector<ll> tr;
int n;

void update(int p, ll val)
{
    for (; p <= n; p = p | (p + 1))
        tr[p] = max(tr[p], val);
}

ll query(int p)
{
    ll ret = 0;
    for (; p >= 0; p = (p & (p + 1)) - 1)
        ret = max(ret, tr[p]);
    return ret;
}

int main() {

    cin >> n;

    tr = vector<ll>(n+1, 0);

    vector<pair<int,int>> fl(n);
    for(int i=0; i<n; i++)
        cin >> fl[i].first;
    for(int i=0; i<n; i++)
        cin >> fl[i].second;

    vector<ll> dp(n+1, 0);
    for(int i=0; i<n; i++)
    {
        dp[fl[i].first] = query(fl[i].first-1) + fl[i].second;
        update(fl[i].first , dp[fl[i].first]);
    }

    ll ans =0;
    for(int i=0; i<=n ;i++)
        ans = max(ans, dp[i]);
   
   cout<<ans;
    
    return 0;
}