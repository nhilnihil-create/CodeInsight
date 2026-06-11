#include<cstdio>
#include<algorithm>
using namespace std;
long long N,A,B;
int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld %lld %lld",&N,&A,&B);
	if(!(A+B<=N+1&&A*B>=N)) {
		printf("-1");
	} else {
		while(N>0) {
			long long x=min(A,N-B+1);
			for(long long i=N-x+1;i<=N;i++)
				printf("%lld ",i);
			N-=x;
			B--;
		}
	}
	return 0;
}