#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

vector<ll> adjlist[100002];
ll dp[100001][2];

//0- white , 1 - black

ll recurse(ll curr_node , ll p_node,int curr_color)
{
    if(adjlist[curr_node].size() == 1)
    {
        return dp[curr_node][curr_color]  = 1;
    }
    else
    {
        if(dp[curr_node][curr_color] != -1) return dp[curr_node][curr_color];
        else
        {
            ll ans = 1;
            for (ll i = 0; i < adjlist[curr_node].size(); i++)
            {
                if(adjlist[curr_node][i] != p_node)
                {
                    if(curr_color == 0) ans = (ans * (recurse(adjlist[curr_node][i],curr_node,0)%mod + recurse(adjlist[curr_node][i],curr_node,1) %mod) % mod)%mod;
                    else ans = ans * (recurse(adjlist[curr_node][i],curr_node,0)%mod)%mod;
                }
            }
            return dp[curr_node][curr_color] = ans %mod;
        }
        
    }
         
}

int main(int argc, char const *argv[])
{
    ll n , v1 , v2;
    cin >> n;
    for (ll i = 0; i < n-1; i++)
    {
        scanf("%lld %lld",&v1,&v2);
        adjlist[v1].push_back(v2);
        adjlist[v2].push_back(v1);
    }

    for (ll i = 0 ; i <= 100000 ; i++) for (int j = 0 ; j <2 ;j++) dp[i][j] = -1;

    //dp[i][j] denotes the number of ways i can color subtree rooted at i with color j;

    ll ans = 1;
    for(ll i =0 ; i < adjlist[1].size() ; i++) ans = ans*(recurse(adjlist[1][i],1,0)%mod)%mod;
    dp[1][1] = ans%mod;
    ans = 1;
    for(ll i =0 ; i < adjlist[1].size() ; i++) ans = (ans*(recurse(adjlist[1][i],1,0)%mod + recurse(adjlist[1][i],1,1) %mod) % mod)%mod;
    dp[1][0] = ans %mod; 

    // for (ll i = 0; i <=n; i++)    {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << (dp[1][1]%mod + dp[1][0]%mod) %mod;
    return 0;
}

