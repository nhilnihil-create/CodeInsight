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
const double EPS=1e-13;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[310010];
int u[310000];
int sz[310000];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	if(b+c>a+1||(long long)b*c<a){
		printf("-1\n");return 0;
	}
	if(b+c==2&&a>1){
		printf("-1\n");return 0;
	}
	sz[b-1]=c;
	for(int i=0;i<b-1;i++)sz[i]=1;
	int rem=a;
	for(int i=0;i<b;i++)rem-=sz[i];
	int at=0;
	while(rem){
		sz[at%(b-1)]++;rem--;at++;
	}
	at=0;
	for(int i=0;i<b;i++){
		int st=at;
		for(int j=0;j<sz[i];j++){
			p[at++]=st+sz[i]-j;
		}
	}
	for(int i=0;i<a;i++)printf("%d ",p[i]);printf("\n");
}