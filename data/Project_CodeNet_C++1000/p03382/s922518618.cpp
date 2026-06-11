// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;
int n,a[200005],mx,mxx;double mm=1e18;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	double t=mx/2.0;for(int i=1;i<=n;i++)if(a[i]!=mx&&fabs(a[i]-t)<mm)mm=fabs(a[i]-t),mxx=a[i];printf("%d %d\n",mx,mxx);

	return 0;
}
