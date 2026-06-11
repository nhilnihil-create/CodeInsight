#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 200000
#define INF 0x7fffffff
int N,A,B;

int main(){
	scanf("%d",&N);
	bool flag=0;
	long long All=0,Rest=INF;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&A,&B);
		All+=B;
		flag|=A!=B;
		if(A>B)
			Rest=min(Rest,1ll*B);
	}
	printf("%lld",flag*(All-Rest));
}