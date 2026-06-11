#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,T;
int x,y,a[maxn];
map<pair<int,int>,bool> s;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(T);
	for (int i=1;i<=n;i++) a[i]=m+1;
	while (T--) {
		read(x); read(y);
		s[make_pair(x,y)]=1;
		a[x]=min(a[x],y);
	}
	int j=1;
	for (int i=1;i<=n;i++) {
		if (a[i+1]<=j) {
			printf("%d\n",i); return 0;
		}
		if (s[make_pair(i+1,j+1)]||j>=m) continue;
		j++;
	}
	printf("%d\n",n);
	return 0;
}