/*input
16
0 5 -4 -5 -8 -4 7 2 -4 0 7 0 2 -3 7 7
5 0 8 -9 3 5 2 -7 2 -7 0 -1 -4 1 -1 9
-4 8 0 -9 8 9 3 1 4 9 6 6 -6 1 8 9
-5 -9 -9 0 -7 6 4 -1 9 -3 -5 0 1 2 -4 1
-8 3 8 -7 0 -5 -9 9 1 -9 -6 -3 -8 3 4 3
-4 5 9 6 -5 0 -6 1 -2 2 0 -5 -2 3 1 2
7 2 3 4 -9 -6 0 -2 -2 -9 -3 9 -2 9 2 -5
2 -7 1 -1 9 1 -2 0 -6 0 -6 6 4 -1 -7 8
-4 2 4 9 1 -2 -2 -6 0 8 -6 -2 -4 8 7 7
0 -7 9 -3 -9 2 -9 0 8 0 0 1 -3 3 -6 -6
7 0 6 -5 -6 0 -3 -6 -6 0 0 5 7 -1 -5 3
0 -1 6 0 -3 -5 9 6 -2 1 5 0 -2 7 -8 0
2 -4 -6 1 -8 -2 -2 4 -4 -3 7 -2 0 -9 7 1
-3 1 1 2 3 3 9 -1 8 3 -1 7 -9 0 -6 -8
7 -1 8 -4 4 1 2 -7 7 -6 -5 -8 7 -6 0 -9
7 9 9 1 3 2 -5 8 7 -6 3 0 1 -8 -9 0
*/

//sometimes it's the people who no one imagines anything of 
//who do the things that no one can imagine.

//code author: iamxlr8

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define inf 1e18L + 5
#define F first
#define S second
#define dbg(x) cout << #x << " = " << x << '\n'
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<ll> pre;
vector<ll> dp;

void fun(ll i,const vector<ll>& not_taken,ll score_so_far,ll mask,ll group)
{
    if(i==not_taken.size())
    {
        dp[mask]=max(dp[mask],score_so_far+pre[group]);
        return;
    }
    fun(i+1,not_taken,score_so_far,mask,group);
    fun(i+1,not_taken,score_so_far,mask|(1<<not_taken[i]),group|(1<<not_taken[i]));
}

void solve()
{
    ll n;
    cin>>n;
    ll v[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cin>>v[i][j];
    }
    dp.resize(1<<n,-inf);
    pre.resize(1<<n,0);
    dp[0]=0;

    // preprocessing
    for(ll mask=0;mask<(1<<n);mask++)
    {
        for(ll i=0;i<n;i++)
        {
            if((1<<i)&mask)
            {
                for(ll j=i+1;j<n;j++)
                {
                    if((1<<j)&mask)
                        pre[mask]+=v[i][j];
                }
            }
        }
    }
    for(ll mask=0;mask<(1<<n);mask++)
    {
        vector<ll> not_taken;
        for(ll i=0;i<n;i++)
        {
            if(!((1<<i)&mask))
                not_taken.push_back(i);
        }
        fun(0,not_taken,dp[mask],mask,0);
    }
    cout<<dp[(1<<n)-1];
}

int main() 
{
    off;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll tests=1;
    // cin>>tests;
    while(tests--)
    {
        solve();
    }
    return 0;
}