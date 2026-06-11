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
int p[210000];
int now[53];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	bool ok=true;
	for(int i=1;i<a;i++){
		if(p[i-1]>=p[i]){
			ok=false;
		}
	}
	if(ok){
		printf("1\n");return 0;
	}
	int left=1;
	int right=a+1;
	while(left+1<right){
		int M=(left+right)/2;
		int sz=0;
		bool ok=true;
		for(int i=0;i<a;i++){
			if(p[i]>50)continue;
			if(sz<p[i]){
				for(int j=sz;j<p[i];j++)now[j]=0;
				sz=p[i];
			}else{
				int at=-1;
				for(int j=p[i]-1;j>=0;j--){
					if(now[j]!=M-1){
						now[j]++;
						at=j;break;
					}
				}

				if(at==-1){
					ok=false;break;
				}
				for(int j=at+1;j<p[i];j++){
					now[j]=0;
				}
				sz=p[i];
			}
		}
		if(ok){
			right=M;
		}else left=M;
	}
	printf("%d\n",right);
}
