#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=1010;
int n,m,x[maxn],y[maxn],mx;
ll w[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(x[i]),read(y[i]);
		m=max(m,abs(x[i])+abs(y[i]));
		mx=max(mx,abs(x[i]));
		mx=max(mx,abs(y[i]));
	}
	for (int i=2;i<=n;i++)
		if ((abs(x[i])+abs(y[i]))%2!=(abs(x[1])+abs(y[1]))%2) {
			printf("-1\n");
			return 0;
		}
	if (mx<=10) {
		printf("%d\n",m);
		for (int i=1;i<=m;i++)
			printf("1 ");
		printf("\n");
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=abs(x[i]);j++)
				if (x[i]>0) printf("R"); else printf("L");
			for (int j=1;j<=abs(y[i]);j++)
				if (y[i]>0) printf("U"); else printf("D");
			for (int j=abs(x[i])+abs(y[i])+1;j<=m;j+=2)
				printf("RL");
			printf("\n");
		}
	} else {
		m=40;
		w[m]=w[m-1]=w[m-2]=w[m-3]=1;
		for (int i=m-4;i>=1;i--) w[i]=w[i+1]*2;
		if ((abs(x[1])+abs(y[1]))%2==1) m--;
		printf("%d\n",m);
		for (int i=1;i<=m;i++)
			printf("%lld ",w[i]);
		printf("\n");
		for (int i=1;i<=n;i++) {
			ll a=x[i],b=y[i];
			for (int j=1;j<=m;j++) {
				if (b>=abs(a)) printf("U"),b-=w[j];
				else if (b<=-abs(a))
					printf("D"),b+=w[j];
				else if (a>=abs(b))
					printf("R"),a-=w[j];
				else printf("L"),a+=w[j];
			}
			printf("\n");
		}
	}
	return 0;
}