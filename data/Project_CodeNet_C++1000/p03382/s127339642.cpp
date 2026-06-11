#include <cstdio>
#include <algorithm>
#define max_n 100000
using namespace std;
int a[max_n+1];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; ++i<=n; scanf("%d",a+i));
	stable_sort(a+1,a+n+1),a[0]=0;
	int t=lower_bound(a+1,a+n+1,a[n]>>1)-a;
    printf("%d %d\n",a[n],a[n]>a[t]+a[t-1]?a[t]:a[t-1]);
    return 0;
}