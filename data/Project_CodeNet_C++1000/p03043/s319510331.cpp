#include<bits/stdc++.h>
using namespace std;
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	double ans=0;
	for(int i=1; i<=a; i++) {
		double pos=1.0/a;
		int now=i;
		while(now<b) {
			now*=2;
			pos/=2;
		}
		ans+=pos;
	}
	printf("%.12f\n",ans);
	return 0;
}