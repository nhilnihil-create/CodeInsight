#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=2e5+5,M=N<<1;

int l[N<<1],r[N<<1],g[N<<1],a[N];
int n;

bool check(int mid) {
	int s=1,ok=1;
	l[1]=1,r[1]=a[1]; g[1]=1;
	fo(i,2,n)
		if (a[i]>a[i-1]) {
			l[++s]=r[s-1]+1;
			r[s]=a[i];
			g[s]=1;
		} else {
			for(;l[s]>a[i];s--);
			r[s]=a[i];
			if(g[s]==mid) {
				int u=s;
				while (g[s]==mid) {g[s]=1;--s;}
				if(s==0) {ok=0;break;}
				else {
					if(l[s]==r[s])++g[s];
					else {	
						l[++s]=r[s-1];
						--r[s-1];
						r[s]=l[s];
						g[s]=g[s-1]+1;
					}
					l[++s]=r[s-1]+1;
					r[s]=a[i];
					g[s]=1;
				}
			} else {
				if (l[s]==r[s]) ++g[s];
				else {
					l[++s]=r[s-1];
					--r[s-1];
					r[s]=l[s];
					g[s]=g[s-1]+1;
				}
			}
		}
	return ok;
}

int main() {
	n=read();
	fo(i,1,n) a[i]=read();
	int l=0,r=n;
	while (l+1<r) {
		int mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
