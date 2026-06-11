#include<bits/stdc++.h>
#define pi pair<int,int>
#define mk make_pair
#define f(i,n) for(int i=1;i<=n;i++)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define fr(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define N 1000000
using namespace std;
vector<int> adj(305);
vector<vector<int>> dp(100005,vector<int> (3,-1));
int n;
int winner(int sum,int ind)
{
    if(sum==0)
        return 1;
    if(sum<0)
        return 0;
    if(dp[sum][ind]==-1)
    {
        int ans=0;
        int cnd;
        if(ind==1)
            cnd=2;
        else
            cnd=1;
        f(i,n)
        {
            ans=ans|winner(sum-adj[i],cnd);
            if(ans==1)
                break;
        }
        //cout<<ans<<"  ";
        dp[sum][ind]=ans;
    }
    //cout<<ind<<" "<<dp[sum][ind]<<endl;
    if(dp[sum][ind]==0)
        return 1;
    else
        return 0;

}



int main()
{
//int n,k;
int k;
    cin>>n>>k;
    f(i,n)
        cin>>adj[i];
    int ans=winner(k,1);
    //cout<<ans;
    if(ans==0)
        cout<<"First";
    else
        cout<<"Second";


}
