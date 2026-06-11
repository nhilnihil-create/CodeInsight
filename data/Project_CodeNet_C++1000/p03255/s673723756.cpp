#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
long long Comb(int a,int b){
 	if(a<b||b<0)return 0;
 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
void init_C(int n){
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<n;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<n;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
// ここから編集しろ
long long x[210000];
long long sum[210000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%lld",x+i);
	// int a=200000;
	// int b=1000000000;
	// for(int i=0;i<a;i++)x[i]=b-i;reverse(x,x+a);
	long long ret=(1LL<<62);
	for(int i=0;i<a;i++){
		sum[i+1]=sum[i]+x[i];
	}
	for(int i=1;i<=a;i++){
		long long tmp=(long long)(i+a)*b;
		int right=a-1;
		int cur=0;
		while(right>=0){
			long long tmp2=sum[right+1]-sum[max(0,right+1-i)];
			tmp2*=max(5,cur*2+3);
			cur++;
			tmp+=tmp2;
			if(tmp>=ret)break;
			right-=i;
		}
		ret=min(ret,tmp);
	}
	printf("%lld\n",ret);
}