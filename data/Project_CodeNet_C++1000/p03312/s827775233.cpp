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
int b[210000];
long long sum[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++){
		sum[i+1]=sum[i]+b[i]*2;
	}
	long long ret=inf;
	for(int i=2;i<=a-2;i++){
		long long M=(sum[i])/2;
		int Lat=lower_bound(sum,sum+a+1,M)-sum;
		M=(sum[a]+sum[i])/2;
		int Rat=lower_bound(sum,sum+a+1,M)-sum;
		for(int j=0;j<2;j++)for(int k=0;k<2;k++){
			int A1=Lat-j;
			int A2=Rat-k;
			if(0<A1&&A1<i&&i<A2&&A2<a){
				ret=min(ret,max(max(sum[A1],sum[i]-sum[A1]),max(sum[A2]-sum[i],sum[a]-sum[A2]))-min(min(sum[A1],sum[i]-sum[A1]),min(sum[A2]-sum[i],sum[a]-sum[A2])));
			}
		}
	}
	printf("%lld\n",ret/2);
}
