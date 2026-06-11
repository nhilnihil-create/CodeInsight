#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N,M;

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d %d",&N,&M);
	if(N==1) {
		printf("%d\n",M);
		return 0;
	}
	int ans=1;
	for(int i=2;i*i<=M;i++)
		if(M%i==0) {
			int tmp=M/i;
			if(tmp/N>0)
				ans=max(ans,i);
			if(i/N>0)ans=max(ans,tmp);
		}
	printf("%d\n",ans);
	return 0;
}

