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
const int C_SIZE = 210000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
// long long C(int a,int b){
// 	if(a<b||b<0)return 0;
// 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
// }
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
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
// ここから編集しろ
int p[210000];
int q[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d%d",p+i,q+i);
	long long ret=0;
	for(int i=0;i<a;i++)ret+=p[i];
	bool ok=true;
	for(int i=0;i<a;i++){
		if(p[i]!=q[i])ok=false;
	}
	if(ok){
		printf("0\n");return 0;
	}
	int mv=mod;
	for(int i=0;i<a;i++){
		if(p[i]>q[i])mv=min(mv,q[i]);
	}
	ret-=mv;
	printf("%lld\n",ret);
}