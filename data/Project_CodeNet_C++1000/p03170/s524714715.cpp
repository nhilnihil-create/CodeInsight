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

ll n,k,ar[N];
bool dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    memset(dp,false,sizeof(dp));
    rep(i,0,n)
    {
        cin >> ar[i];
    }

    rep(i,1,k+1)
    {
        rep(j,0,n)
        {
            if(i-ar[j]<0)
                break;

            if(!dp[i-ar[j]])
            {
                dp[i]=true;
                break;
            }
        }
    }

    if(dp[k])
        cout << "First\n";
    else
        cout << "Second\n";

    return 0;
}

