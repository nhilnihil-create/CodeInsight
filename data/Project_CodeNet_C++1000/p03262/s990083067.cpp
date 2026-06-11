#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,ans,a[maxn];
int gcd(int x,int y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
int main() {
	
	read(n); read(a[n+1]);
	for (int i=1;i<=n;i++) read(a[i]);
	n++;
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) ans=gcd(ans,a[i+1]-a[i]);
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