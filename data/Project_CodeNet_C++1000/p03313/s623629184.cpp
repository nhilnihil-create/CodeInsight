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
int p[1100000];
pair<int,int>dp[1100000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<(1<<a);i++){
		scanf("%d",p+i);
	}
	int n=(1<<a);
	for(int i=0;i<n;i++){
		dp[i]=make_pair(p[i],-1);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<n;j++){
			if(j&(1<<i)){
				pair<int,int>tmp=dp[j-(1<<i)];
				if(tmp.first>dp[j].first){
					dp[j].second=dp[j].first;dp[j].first=tmp.first;
				}else if(tmp.first>dp[j].second){
					dp[j].second=tmp.first;
				}
				if(tmp.second>dp[j].first){
					dp[j].second=dp[j].first;dp[j].first=tmp.second;
				}else if(tmp.second>dp[j].second){
					dp[j].second=tmp.second;
				}
			}
		}
	}
	int ret=0;
	for(int i=1;i<n;i++){
		ret=max(ret,dp[i].first+dp[i].second);
		printf("%d\n",ret);
	}
}
