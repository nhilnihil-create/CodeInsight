/*
    Author: aksayushx
*/

#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
}
ll power(ll x, ll y)  
{  
    ll res = 1; 
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x)%mod;  
        y = y>>1; 
        x = (x*x)%mod;  
    }  
    return res;  
} 

void aksayushx()
{
    int h,w;
    cin>>h>>w;
    vector<string> grid(h);
    for(int i=0;i<h;i++)
    cin>>grid[i];
    ll dp[h][w];
    dp[0][0]=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            char ch=grid[i][j];
            if(i==0 && j==0)
            continue;
            if(ch=='#')
            {
                dp[i][j]=0;
                continue;
            }
            if(i-1>=0 && j-1>=0)
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
            else if(i-1>=0)
            {
                dp[i][j]=dp[i-1][j];
            }
            else if(j-1>=0)
            {
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    cout<<dp[h-1][w-1];
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    while(test--)
        aksayushx();
    return 0;
}
