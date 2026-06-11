#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int N=100005;
const int P=998244353;

int n;
double a[N];
int res;

void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(fabs(a[i]-a[n]/2)<fabs(a[res]-a[n]/2)) res=i;
	}
	printf("%.0lf %.0lf\n",a[n],a[res]);
}

int main(){
	init();
	return 0;
}