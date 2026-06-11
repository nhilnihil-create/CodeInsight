#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define INF LLONG_MAX
#define eps LDBL_EPSILON
#define moder 998244353
#define pie 3.141592653589793238462643383279
#define P std::pair<int,int>
#define prique priority_queue
using namespace std;
int n,a,b,k;
int dp[300010];
int kaijo(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans%=moder;
	}
	return ans;
}
int mypow(int x,int y){
	if(y==0)return 1;
	if(y%2)return mypow(x,y-1)*x%moder;
	return mypow(x,y/2)*mypow(x,y/2)%moder;
}
int comb(int x,int y){
	return dp[x]*mypow(dp[y],moder-2)%moder*mypow(dp[x-y],moder-2)%moder;
}
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
signed main(){
	cin>>n>>a>>b>>k;
	int cnt=INF;
	rep(i,n){
		if((k-a*i)%b==0){
			cnt=i;
			break;
		}
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]*i;
		dp[i]%=moder;
	}
	if(cnt==INF){
		cout<<0<<endl;
		return 0;
	}
	int ans=0;
	int memo=b/gcd(a,b);
	while(k>=a*cnt){
		if(cnt<=n&&(k-a*cnt)/b<=n)ans+=comb(n,cnt)*comb(n,(k-a*cnt)/b)%moder;
		cnt+=memo;
		ans%=moder;
	}
	cout<<ans<<endl;
	return 0;
}