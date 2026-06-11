#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


/*
1~nを左から順に配置していく
dp(i,j)=iをjに置く
*/

ll n,A,B,a[5010],dp[5010]={},inf=1e18,ans=1e18;

int main(void){
	cin>>n>>A>>B;
	reg(i,1,n){
		ll x;
		cin>>x;
		a[x]=i;
	}
	reg(i,1,n){
		ll c=inf;
		reg(j,1,n){
			c=min(c,dp[j]);
			if(a[i]<j){
				dp[j]=c+A;
			}else if(a[i]>j){
				dp[j]=c+B;
			}else{
				dp[j]=c;
			}
		}
	}
	reg(i,1,n)ans=min(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}