#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int maxn=3e3+10;
const ll mod=1e9+7;
template<typename T> void read(T &x){
	T f=1;x=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	x*=f;
}
int n;
ll ans;
string s;
ll dp[maxn][maxn];
ll pre[maxn][maxn];
int main(){
	read(n);
	cin>>s;
	dp[0][0]=1;
	for(re int i=1;i<=n;i++){
		pre[0][i]=1;
	}
	for(re int i=1;i<n;i++){
		for(re int j=1;j<=n;j++){
			if(s[i-1]=='<'){
				dp[i][j]=pre[i-1][j-1]%mod;
				pre[i][j]=(pre[i][j-1]+dp[i][j])%mod; 
			}
			else{
				dp[i][j]=(pre[i-1][i]-pre[i-1][j-1]+mod)%mod;
				pre[i][j]=(pre[i][j-1]+dp[i][j])%mod;
			}
		}
	}
	for(re int i=1;i<=n;i++){
		ans=(ans+dp[n-1][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
