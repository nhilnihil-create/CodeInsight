#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std; 
const long long  mod=998244353;
typedef long long LL;
const int N=3e5+5;
LL fac[N],inv[N];
LL quickPow(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1){
			ans=(ans*a)%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
LL C(int n,int m){
	if(n<0||m<0||m>n) return 0;
	if(n==m||m==0) return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void init(){
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	inv[N-1]=quickPow(fac[N-1],mod-2);
	for(int i=N-2;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
LL Lucas(int n,int m){
	if(m==0) return 1;
	return C(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod;
}
int main(){
	LL n,a,b,k,j,ans=0;
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	if(k==0){
		printf("1");
		return 0;
	} 
	init();
	for(int i=0;i<=n;i++){
		if((k-a*i)%b==0&&(k-a*i)>=0){
			j=(k-a*i)/b;
			if(j>n) continue;
			ans=(ans+C(n,i)*C(n,j))%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}