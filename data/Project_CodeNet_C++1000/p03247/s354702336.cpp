#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1005;

int n,x[N],y[N],d[N],m;
bool in[2];

int main() {
	scanf("%d",&n);
	fo(i,1,n) {
		scanf("%d%d",&x[i],&y[i]);
		in[(x[i]+y[i])&1]=1;
	}
	if (in[0]&&in[1]) {puts("-1");return 0;}
	if (in[0]) d[++m]=1;
	fd(i,30,0) d[++m]=1<<i;
	printf("%d\n",m);
	fo(i,1,m) printf("%d ",d[i]);
	puts("");
	fo(i,1,n) {
		fo(j,1,m)
			if (abs(x[i])>abs(y[i])) {
				if (x[i]>0) x[i]-=d[j],putchar('R');
				else x[i]+=d[j],putchar('L');
			} else {
				if (y[i]>0) y[i]-=d[j],putchar('U');
				else y[i]+=d[j],putchar('D');
			}
		puts("");
	}
	return 0;
}