#include<bits/stdc++.h>

using namespace std;

#define INF 1/0.
#define fac(x) lgammal((x)+1.0)
#define C(x,y) (x<y?-INF:fac(x)-fac(y)-fac(x-y))

int n,a[300000],x,y;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	x=-1; y=0;
	for (int i=1;i<=n;++i){
		int k=lower_bound(a+1,a+n+1,a[i]/2)-a;
		if (k-1>0){
			if (C(a[i],a[k-1])>C(x,y)){
				x=a[i]; y=a[k-1];
			}
		}
		if (k<i){
			if (C(a[i],a[k])>C(x,y)){
				x=a[i]; y=a[k];
			}
		}
	}
	printf("%d %d\n",x,y);
	
	return 0;
}
			