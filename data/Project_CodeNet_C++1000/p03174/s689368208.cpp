#include <iostream>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

typedef long long int ll;

ll MOD = pow(10,9) + 7;

inline bool check(int mask,int p)
{
    int z = 1<<p;
    z &= mask;

    return z;
}

inline void set_bit(int& mask,int p)
{
    int z = 1<<p;
    mask |= z;
}

inline void clear_bit(int& mask,int p)
{
    int z = 1<<p;
    mask ^= z;
}


ll helper(vector<list<int>>& adj,vector<ll>& dp,int& mask,int woman)
{
    int n = adj.size();

    if (mask == (1<<n)-1) return 1;
    //if (woman == n) return 0;

    if (dp[mask] != -1) return dp[mask];

    ll ans = 0;

    for (int man: adj[woman])
    {
        if (!check(mask,man))
        {
            set_bit(mask,man);
            ans += helper(adj,dp,mask,woman+1);
            ans %= MOD;
            clear_bit(mask,man);
        }
    }

    dp[mask] = ans;

    return ans;
}

ll solve(vector<list<int>>& adj)
{
    int mask = 0;
    int n = adj.size();
    vector<ll> dp((1<<n),-1);

    ll ans = helper(adj,dp,mask,0);

    return ans;
}



int main()
{
    ll N;
    cin>>N;
    vector<vector<bool>> G(N,vector<bool>(N));

    for (int i=0;i<N;++i)
    {
        for (int j=0;j<N;++j)
        {
            bool b;
            cin>>b;
            G[i][j] = b;
        }
    }

    //Woman: Rows
    //Man: Col

    vector<list<int>> adj(N);

    for (ll i=0;i<N;++i)
    {
        for (ll j=0;j<N;++j)
        {
            if (G[i][j]) adj[j].push_back(i);
        }
    }

    cout<<solve(adj)<<endl;

    return 0;
}
