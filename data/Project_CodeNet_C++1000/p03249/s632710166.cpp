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
long long d[110000];
pair<long long,int> p[110000];
int sz[110000];
int L[110000];
int R[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%lld",d+i);
		p[i]=make_pair(d[i],i);
	}
	std::sort(p,p+a);
	int ind=0;
	long long sum=0;
	for(int i=0;i<a;i++)sz[i]=1;
	for(int i=a-1;i>=1;i--){
		int at=p[i].second;
		long long C=p[i].first;
		int ad=a-2*sz[at];
		if(ad<=0){
			printf("-1\n");return 0;
		}
		int in=lower_bound(p,p+a,make_pair(C-ad,0))-p;
		if(p[in].first!=C-ad){
			printf("-1\n");return 0;
		}
		L[ind]=p[i].second;
		R[ind++]=p[in].second;
		sum+=(long long)sz[at]*(a-sz[at])*2;
	//	printf("%d %d\n",L[ind-1],R[ind-1]);
		sz[p[in].second]+=sz[at];
	}
	long long dsum=0;
	for(int i=0;i<a;i++){
		dsum+=d[i];
	}
	if(sum!=dsum){
		printf("-1\n");return 0;
	}
	for(int i=0;i<ind;i++){
		printf("%d %d\n",L[i]+1,R[i]+1);
	}
}
