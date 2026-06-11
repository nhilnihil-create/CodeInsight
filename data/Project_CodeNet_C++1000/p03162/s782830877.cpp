#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

struct plans{

    int x,y,z;
};

int32_t main()
{
    int n;cin>>n;
    vector<plans> vp;

    int x,y,z;
    for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        vp.pb({x,y,z});
    }

    int dp[n+1][3];
    memset(dp,0,sizeof(dp));

    dp[0][0]=vp[0].x;
    dp[0][1]=vp[0].y;
    dp[0][2]=vp[0].z;

    for(int i=1;i<n;i++){
        
        dp[i][0]=vp[i].x + max(dp[i-1][2],dp[i-1][1]);
        dp[i][1]=vp[i].y + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=vp[i].z + max(dp[i-1][1],dp[i-1][0]);
    }

    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;


    return 0;
}