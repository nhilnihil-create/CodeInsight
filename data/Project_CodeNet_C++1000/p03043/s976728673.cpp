#include<bits/stdc++.h>
using namespace std;
long double n,k,ans;
int main() {
	scanf("%Lf%Lf",&n,&k);
	for(register long double i=1; i<=n; i+=1) {
		if(i>=k) {
			ans+=1.0/n;
			continue;
		}
		long double x=i,cnt=1;
		while(x<k) {
			x*=2.0;
			cnt*=2.0;
		}
		ans+=(1.0/n)*(1.0/cnt);
	}
	printf("%.9Lf",ans);
	return 0;
}