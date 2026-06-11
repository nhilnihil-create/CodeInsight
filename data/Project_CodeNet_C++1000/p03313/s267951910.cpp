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
pi dp[N];

bool ison(ll mask,ll ind)
{
    return (mask>>ind)&1;
}

void solve()
{
    dp[0].first = ar[0];
    dp[0].second = -INF;

    rep(i,1,ola)
    {
        dp[i].first = -INF;
        dp[i].second = -INF;

       // cout << "i: " << i << "\n";

        for(int j = i;j >= 0;j = i&(j-1))
        {
        //    cout << j << " ";
            if(ar[j] >= dp[i].first)
            {
                dp[i].second = dp[i].first;
                dp[i].first=ar[j];
            }
            else if(ar[j] > dp[i].second)
            {
                dp[i].second=ar[j];
            }

            if(j == 0)
                break;
        }

        //cout << endl << dp[i].first << " " << dp[i].second << endl;;

        ans[i] = dp[i].first+dp[i].second;
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
