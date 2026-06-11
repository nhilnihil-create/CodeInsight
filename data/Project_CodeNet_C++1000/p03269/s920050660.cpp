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
int p3[110];
int main(){
	int a;scanf("%d",&a);
	p3[0]=1;
	for(int i=1;i<15;i++)p3[i]=p3[i-1]*3;
	vector<pair<pair<int,int>,int> >v;
	for(int i=2;i<=14;i++){
		v.push_back(make_pair(make_pair(i,i+1),0));
		v.push_back(make_pair(make_pair(i,i+1),p3[14-i]));
		if(p3[14-i]*2<=1000000)v.push_back(make_pair(make_pair(i,i+1),p3[14-i]*2));
		
	}
	int cur=0;
	for(int i=12;i>=0;i--){
		if(a%p3[i+1]/p3[i]==2){
			v.push_back(make_pair(make_pair(1,15-i),cur+p3[i]));
		}
		if(a%p3[i+1]/p3[i]>=1){
			v.push_back(make_pair(make_pair(1,15-i),cur));
		}
		cur+=a%p3[i+1]/p3[i]*p3[i];
	}
	printf("15 %d\n",(int)v.size());
	for(int i=0;i<v.size();i++)printf("%d %d %d\n",v[i].first.first,v[i].first.second,v[i].second);
}
