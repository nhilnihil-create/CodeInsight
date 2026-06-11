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
const long double EPS=1e-13;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}

int main(){
	int a;scanf("%d",&a);
	if(a==3){
		printf("2 5 63\n");
		return 0;
	}
	int t2=1;
	int t3=2;
	int t4=1;
	int t6=0;
	a-=4;
	int ad=min(4999,a/2);
	t2+=ad;
	t4+=ad;
	a-=ad*2;
	ad=min(4998,a-a%2);
	t3+=ad;
	a-=ad;
	t6+=a;
	for(int i=0;i<t2;i++)printf("%d ",i*6+2);
	for(int i=0;i<t3;i++)printf("%d ",i*6+3);
	for(int i=0;i<t4;i++)printf("%d ",i*6+4);
	for(int i=0;i<t6;i++)printf("%d ",i*6+6);

	printf("\n");
}