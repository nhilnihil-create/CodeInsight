#include <bits/stdc++.h>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fast() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define test() ll tc;cin>>tc;while(tc--)
using namespace std;


///dp[i] is the number of ways the womens in set i can be assigned to the ///first/// j mens
///such that each women gets a men she likes. Note that this may be 00 if no such assignment is possible.









void add_self(int &a,int b)
{
    a+=b;
    if(a>mod)
    {
        a-=mod;
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int>> can(n,vector<int>(n));
    f(i,0,n)
    {
        f(j,0,n)
        {
            scanf("%d",&can[i][j]);
        }
    }
    ///1<<n=2^n
    vector<int> dp(1<<n);
    dp[0]=1;
    ///mask represent women that aren't yet matched
    ///mask=000 no women is paired,001 means 1st women is paired,010 means 2nd women is paired
    ///a denotes the first mens whom which womens are paired
    ///m2 is mask after women is paired with new men
    f(mask,0,(1<<n)-1)
    {
        //cout<<"mask= "<<mask<<endl;
        int a = __builtin_popcount(mask);
        f(b,0,n)
        {
            //cout<<"a= "<<a<<endl;
            if(can[a][b] && !(mask & (1<<b) ))///if can[a][b] =1 and women is not paired yet
            {
                int m2 = mask | (1<<b); /// m2 is new mask , women is paired
                //cout<<"m2= "<<m2<<endl;
                //dp[m2]+=dp[mask];
                add_self(dp[m2],dp[mask]);///dp[m2]=(dp[m2]+dp[mask])%mod
                //cout<<"dp[m2] = "<<dp[m2]<<endl;
            }
        }

    }
    /*f(i,0,(1<<n))
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/
    cout<<dp[(1<<n)-1];
    return 0;
}

