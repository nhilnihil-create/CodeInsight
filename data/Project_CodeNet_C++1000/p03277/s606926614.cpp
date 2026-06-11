// #pragma GCC target("avx2")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
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
#include<numeric>
using namespace std;
const long long mod=998244353;
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
	if(a<0LL)return 0;
	if(b<0LL)return 0;
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
int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
// ここから編集しろ
int p[110000];

pair<int,int>q[110000];
int bit[210000];
int sum(int a,int b){
	if(a)return sum(0,b)-sum(0,a-1);
	int ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
	return ret;
}
void add(int a,int b){
	for(;a<210000;a|=a+1)bit[a]+=b;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	for(int i=0;i<a;i++)q[i]=make_pair(p[i],i);
	std::sort(q,q+a);
	int left=-1;
	int right=a;
	while(left+1<right){
		int M=(left+right)/2;
		long long cnt=0;
		for(int i=0;i<210000;i++)bit[i]=0;
		int at=100000;
		add(at,1);
		for(int i=0;i<a;i++){
			if(make_pair(p[i],i)>=q[M]){
				at++;
			}else at--;
			cnt+=sum(0,at);
			add(at,1);
		}
	//	printf("%d %d: %lld\n",q[M].first,q[M].second,cnt);
		if(cnt<((long long)a*(a+1)/2+1)/2)right=M;
		else left=M;
	}
	printf("%d\n",q[left].first);
}