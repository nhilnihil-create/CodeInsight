#include<cstdio>
int n,k;
double ans;
int s[21];
int main() {
	scanf("%d %d",&n,&k);
	s[0]=1;
	for(int i=1;i<20;i++) s[i]=s[i-1]*2;
	for(int i=1;i<=n;i++) {
		for(int j=19;j>=0;j--) {
			if(1LL*i*s[j]<1LL*k) {
				double l=1.0/s[j+1];
				ans+=1.0/s[j+1];
				break;
			}
		}
	}
	if(n>=k) ans+=(double)(n-k+1);
	printf("%.12lf",ans/n-1e-10);
	return 0;
}