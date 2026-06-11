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
#define N 3004
#define INF 1e9+7

using namespace std;

ll n,mod=1e9+7;
string s;
ll dp[N][N];
ll pre[N][2];

ll get_sum(ll i,ll j,ll id)
{
    if(i > j)
        return 0;

    return (pre[j][id]-pre[i-1][id]+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> s;

    dp[0][1] = 1;
    pre[1][0] = 1;

    rep(i,1,n)
    {
        rep(j,1,i+2)
        {
            if(s[i-1] == '>')
            {
                dp[i][j] = get_sum(j,i,(i+1)%2);
            }
            else
            {
                dp[i][j] = get_sum(1,j-1,(i+1)%2);
            }

       //     cout << dp[i][j] << " ";

            pre[j][i%2] = (pre[j-1][i%2]+dp[i][j])%mod;
        }

   //     cout << endl;
    }

    cout << get_sum(1,n,(n+1)%2) << "\n";

    return 0;
}
