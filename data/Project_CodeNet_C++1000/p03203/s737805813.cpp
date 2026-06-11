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
int x[210000];
int y[210000];
set<int> S[210000];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<c;i++){
		scanf("%d%d",x+i,y+i);
		x[i]--;y[i]--;
		S[y[i]].insert(x[i]);
	}
	for(int i=0;i<b;i++){
		S[i].insert(a);
	}

	int ret=mod;
	int ss=0;

	for(int i=0;i<b;i++){
		int nx=*(S[i].lower_bound(ss));
		if(ss+1==nx){
			ret=min(ret,nx);
			break;
		}else{
			ret=min(ret,nx);
		}
		while(1){
			if(S[i].count(ss+1)){
				i=b;break;
			}
			ss++;
			if(i<b-1&&S[i+1].count(ss)==0){
				break;
			}
		}
	}
	printf("%d\n",ret);
}
