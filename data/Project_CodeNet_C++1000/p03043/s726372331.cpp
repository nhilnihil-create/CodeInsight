#include <cstdio>
int n,k;
long double ans;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i){
		if(i > k){
			ans += (n-i+1);
			break;
		}
		long double vo = 1;
		int cnt = 0,pos = i;
		while(pos < k)
			++cnt,pos*=2,vo/=2;
		ans += vo;
	}
	printf("%.12Lf",ans/n);
	return 0;
}