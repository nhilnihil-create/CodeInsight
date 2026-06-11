#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stack>
#include<cmath>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();	}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	x*=f;
}
const int mod = 998244353;
inline int quick_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}
int inv[300100],jc[300100];
inline int C(int n,int m){
	return ((jc[n]*inv[n-m])%mod*inv[m])%mod;
}
int n,a,b,k,ans;
//void write(int x){
//	if(x<0) putchar('-'),x=-x;
//	if(x>9) write(x/10);
//	putchar(x%10+48);
//}
signed main()
{
	read(n),read(a),read(b),read(k); 
	jc[0]=1;
	for(int i=1;i<=300000;i++) jc[i]=(jc[i-1]*i)%mod;
	inv[300000] = quick_pow(jc[300000],mod-2);
    inv[0]=1;
	for(int i=299999;i;i--) inv[i]=(inv[i+1]*(i+1))%mod;
//	cout<<inv[2]<<endl;
//    cout<<" KLK "<<endl; 
	//a b为得分 答案为k
//	cout<<C(2,2)<<endl; 
	for(int i=0;i<=k/a&&i<=n;i++){
//		if(i>=100000) write(i),cout<<endl;
		if((k-i*a)%b!=0) continue;
		int j=(k-i*a)/b;
		if(j>n) continue;
		ans+=(C(n,i)*C(n,j))%mod;
		ans%=mod;
//		int tmp=ans;
//		cout<<tmp<<endl;
//		cout<<ans<<endl;
//	    printf("%lld YYY\n",ans);
	}
//	cout<<ans<<endl;
	printf("%lld",ans);
//	write(ans); 
	return 0;
}