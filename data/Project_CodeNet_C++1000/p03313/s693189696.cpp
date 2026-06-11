#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll ola,n,ar[N],ans[N];
set < pi > dp[N];

bool ison(ll mask,ll ind)
{
    return (mask>>ind)&1;
}

void solve()
{
    dp[0].insert(mp(ar[0],0));

    rep(i,1,ola)
    {
        dp[i].insert(mp(ar[i],i));

        rep(b,0,n)
        {
            if(!ison(i,b))
                continue;

            ll j = i^(1 << b);

            for(set < pi >::iterator it = dp[j].begin();it!=dp[j].end();it++)
                dp[i].insert(*it);

            while(dp[i].size() > 2)
                dp[i].erase(dp[i].begin());
        }

        for(set < pi >::iterator it = dp[i].begin();it!=dp[i].end();it++)
            ans[i] += (*it).first;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ola = (1<<n);

    rep(i,0,ola)
        cin >> ar[i];

    solve();

    rep(k,1,ola)
    {
        ans[k] = max(ans[k],ans[k-1]);
        cout << ans[k] << "\n";
  //      cout << dp[k].first << " " <<dp[k].second << "\n";
    }

    return 0;
}
