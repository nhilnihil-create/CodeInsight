
//minimum number of insertion and deletion to make string b from string a

#include<bits/stdc++.h>
#define fo(i,n) for(int i=1;i<=n;i++)
#define fo1(i,n) for(int i=0;i<n;i++)
#define llu long long int
#define vi vector <int>
#define pb push_back
#define mod 1000000007

using namespace std;

int a[200001];
int dp[200001];
int loop(int i,int n)
{
    if(i >= n)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int x = INT_MAX ,y = INT_MAX;
    if((i+1)<=n)
        x = abs(a[i]-a[i+1]) + loop(i+1,n);
    if((i+2)<=n)
        y = abs(a[i]-a[i+2]) + loop(i+2,n);
    return dp[i] = min(x,y);

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
       // int a[n];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<loop(1,n)<<"\n";
    }
}

