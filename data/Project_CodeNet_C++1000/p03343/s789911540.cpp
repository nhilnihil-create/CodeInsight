#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(2e9);
const int maxn=2010;
int n,k,q,a[maxn],ans,b[maxn],res[maxn];
int solve(int x) {
	int s=-1,sz=0;
	for (int i=1;i<=n+1;i++)
		if (a[i]>=a[x]) {
			if (s==-1) s=i;
		}
		else if (s!=-1) {
			if (i-s>=k) {
				for (int j=s;j<i;j++) b[j-s+1]=a[j];
				sort(b+1,b+i-s+1);
				for (int j=1;j+k-1<=i-s;j++) res[++sz]=b[j];
			}
			s=-1;
		}
	if (sz<q) return INF;
	sort(res+1,res+sz+1);
	return res[q]-a[x];
}
int main() {
	
	read(n),read(k),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	ans=INF;
	for (int i=1;i<=n;i++) ans=min(ans,solve(i));
	printf("%d\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/