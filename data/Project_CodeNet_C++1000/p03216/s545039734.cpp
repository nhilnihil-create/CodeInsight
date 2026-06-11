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
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
char in[1100000];

int main(){
	int a;scanf("%d",&a);
	scanf("%s",in);
	int b;scanf("%d",&b);
	while(b--){
		int K;scanf("%d",&K);
		long long ret=0;
		long long sum=0;
		int at=0;
		int nm=0;
		for(int i=0;i<a;i++){
			if(i-K>=0){
				if(in[i-K]=='D'){
					sum-=at;
					nm--;
				}else if(in[i-K]=='M'){
					at--;
				}
			}
			if(in[i]=='D'){
				nm++;
			}else if(in[i]=='M'){
				at++;
				sum+=nm;
			}else if(in[i]=='C'){
				ret+=sum;
			}
		}
		printf("%lld\n",ret);
	}
}