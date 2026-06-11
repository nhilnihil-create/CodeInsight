#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(long long int i=a;i<b;i++)
#define f(i,n) for(long long int i=0;i<n;i++)
typedef unsigned long long ull;
typedef long long ll;
#define vint vector<int>
#define vll vector<long long int>
#define pb(a) push_back(a);
#define bug(x) cout<<#x<<" = "<<x<<"\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

long int dp[101][100002];
const int M = 1000000007;

int main(){
	fastio;
	ll n,k; cin>>n>>k;
	vll a(n);
	f(i,n){cin>>a[i];}
	// memset(dp,0,sizeof(dp));
	vll pre(k+1);
	pre[0]=1;
	ll sum = 0;
	f(i,n+1){
		if(i!=0){sum+=a[i-1];	if(sum>k) sum=k;}
		f(j,k+1){
			// cout<<"i="<<i<<" j="<<j<<" sum="<<sum;
			if(j==0){
				dp[i][j]=1;
			}
			else if(i==0){// || sum<j){
				// cout<<" ~ ";
				dp[i][j]=0;
				// cout<<"("<<dp[i][j]<<") ";
			}
			else{
				dp[i][j] = pre[j]%M;
				// cout<<"("<<dp[i][j]<<") ";
				if(j-a[i-1]-1>=0){
					dp[i][j]+=(M-pre[j-a[i-1]-1])%M; dp[i][j]%=M;
				}
			}
			// cout<<dp[i][j]<<" ";
		}
		// cout<<"\nprinting pre\n";
		// cout<<pre[0]<<" ";
		// if(i>=1)pre[0] = dp[i-1][0];
		F(j,1,k+1){
			pre[j] = (pre[j-1]+dp[i][j])%M;
			// cout<<pre[j]<<" ";
		}
		// cout<<"\n";
	}
	cout<<dp[n][k]<<"\n";
	return 0;
}