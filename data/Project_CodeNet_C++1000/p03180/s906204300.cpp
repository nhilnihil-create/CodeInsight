#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
#define turbo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define qi queue<int>
#define ld long double

using namespace std;

/*---------------------------------------------------------///CODE///---------------------------------------------------------*/

const int N = 17;
ll graph[N][N];
ll dp[(1 << N)];
ll cost[(1 << N)];

ll count_cost(ll m)
{
    ll ans = 0;

    for(int i = 0; i < N; i++)
        if(((m >> i) | 1) == (m >> i))
            for(int j =  i + 1; j < N; j++)
                if(((m >> j) | 1) == (m >> j))
                    ans += graph[i][j];
    return ans;
}
int main()
{
    turbo

    int n; cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int x; cin >> x;
            graph[i][j] = x;
        }
    for(int i = 0; i < (1 << n); i++)
        cost[i] = count_cost(i);
    
    for(int i = 0; i < (1 << n); i++)
        for(int j = i; j >= 0; j = (j - 1) & i)
        {
            dp[i] = max(dp[i], cost[j] + dp[i ^ j]); 
            if(j == 0) break;
        }

    cout << dp[(1 << n) - 1];
    return 0;
}