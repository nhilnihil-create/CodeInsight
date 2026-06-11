/*
f[i][j]用数字1到i放前i位且最后一位是j的合法方案 
n=4,<><
  j=0,1,2,3,4
i=0 0 0 0 0 0
i=1 0 1 0 0 0
i=2 0 0 1 0 0
i=3 0 1 1 0 0
i=4 0 0 1 2 2
3<4>1<2
2<4>1<3
1<4>2<3
2<3>1<4
1<3>2<4
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3009;
const ll MOD=1e9+7;
char s[N];
ll n,f[N][N];
int main(){
	cin>>n;
	for(ll i=1;i<=n;++i)cin>>s[i];
	f[1][1]=1;
	for(ll i=2;i<=n;++i){
		if(s[i-1]=='<'){
			for(ll j=2;j<=i;++j)
				f[i][j]=(f[i][j-1]+f[i-1][j-1])%MOD;		
		}
		else{
			for(ll j=i-1;j>=1;--j)
				f[i][j]=(f[i][j+1]+f[i-1][j])%MOD;
		}
	}	
	ll ans=0;
	for(ll j=1;j<=n;++j)ans=(ans+f[n][j])%MOD;
	cout<<ans<<endl;	
    return 0;
}