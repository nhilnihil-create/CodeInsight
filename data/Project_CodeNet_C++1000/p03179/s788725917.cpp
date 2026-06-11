#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define vec vector<int> 
#define int long long 
#define pii pair<int,int>
string s;
int n;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ios_base& scientific (ios_base& str);
	
	int t=1;
	//cin>>t;
	while(t--){
		//int n;
		cin>>n;
		//int arr[n][n];
		//bool visited[n+1];
		int dp[n+1][n+1];
		memset(dp,0,sizeof(dp));
		cin>>s;
		s=" "+s;
		int pre_sum[n+1]={0};
		pre_sum[0]=0;
		pre_sum[1]=1;
		memset(dp,0,sizeof(dp));
		dp[1][0]=0;
		dp[1][1]=1;
		REP(i,1,n+1){
			pre_sum[i]=pre_sum[i-1]+dp[1][i];
		}
		REP(i,2,n+1){
			REP(j,1,i+1){
				if(s[i-1]=='<'){
					dp[i][j]=(pre_sum[j-1]%mod);
				}
				else{
					dp[i][j]=((pre_sum[i-1]%mod)-(pre_sum[j-1]%mod)+mod)%mod;
				}
				dp[i][j]%=mod;
			}
			dp[i][0]=0;
			REP(j,1,i+1){
				pre_sum[j]=((dp[i][j]%mod)+(pre_sum[j-1]%mod))%mod;
				pre_sum[j]%=mod;
			//	cout<<pre_sum[j]<<" ";
			}
		//	cout<<endl;
		}
		int ans=0;
		
		REP(i,1,n+1){
			ans+=dp[n][i]%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	//exit();
	return 0;
}
