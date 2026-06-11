
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<cassert>
#include<algorithm>
using namespace std;
typedef long long  ll;
typedef long double ld;
//typedef vector<int>        vi;
//typedef vector<ll>        vl;
//#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
//#define pb    push_back;
//#define fo(i,n) for(int i=0;i<n;i++)
int dp[100005];
int arr[100005];
const int INF=1e9 + 5;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    dp[1]=0;
    dp[2]=abs(arr[1]-arr[2]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=INF;
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j<i)
                dp[i]=min(dp[i],dp[i-j]+abs(arr[i-j]-arr[i]));
        }
    }
    cout<<dp[n]<<endl;
   
    return 0;
}
 
