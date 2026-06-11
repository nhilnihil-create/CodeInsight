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

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int A=0;
	int B=0;
	int C=0;
	for(int i=0;i<a;i++){
		int p;scanf("%d",&p);
		if(p<=b)A++;
		else if(p<=c)B++;
		else C++;
	}
	printf("%d\n",min(A,min(B,C)));
}
