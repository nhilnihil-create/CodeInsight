#include<bits/stdc++.h>
 
#define mp          make_pair
#define pb          push_back
#define lb          lower_bound
#define ub          upper_bound
#define ff          first
#define ss          second
#define ii          pair<int,int>
#define mod         int(1e9+7)
#define inf         1e18
 
typedef long long int ll;
typedef long double ld;
 
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
const int N=3e5;

int dp[102][100005];
int A[100];

void solve()
{
	int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=0;i<=A[0];i++)
        dp[0][i]=1;

    for(int i=1;i<n;i++)
    {
        vector<int> prefix_sum(k+1);
        prefix_sum[0]=dp[i-1][0];
        for(int j=1;j<k+1;j++){
            prefix_sum[j]=(prefix_sum[j-1]+dp[i-1][j])%mod;
        }
        for(int j=0;j<k+1;j++)
        {
            if(j>A[i])
            {
                dp[i][j]=(prefix_sum[j]+mod-prefix_sum[j-A[i]-1])%mod;
            }
              else
                dp[i][j]=prefix_sum[j];
            
        }
    }
    cout<<dp[n-1][k]<<endl;
    return ;
}
 
int main()
{
    fio
 
    int t=1;
//    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}