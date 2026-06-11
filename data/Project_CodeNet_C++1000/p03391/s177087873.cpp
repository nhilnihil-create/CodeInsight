#include<cstdio>

int n,a,b,tmp=1e9+7;
long long sum;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d %d",&a,&b);
		sum+=a;
		if(a>b)
			if(b<tmp)
				tmp=b;
	}
	if(tmp==1e9+7) printf("0\n");
	else printf("%lld\n",sum-tmp);
	return 0;
}