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

int32_t main()
{
    int n;cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;dp[1]=abs(arr[1]-arr[0]);

    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]) , dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    cout<<dp[n-1]<<endl;

    
    return 0;
}