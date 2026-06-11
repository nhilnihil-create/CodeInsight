#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int N;
	long long ans=0,minb=1e9;
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		long long a,b;
		scanf("%lld %lld",&a,&b);
		ans+=a;
		if(a>b)minb=min(minb,b);
	}
	printf("%lld\n",minb==1e9?0:ans-minb);
	return 0;
}