#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n,ans;
int solve(int x) {
	int cnt=0;
	for (int i=1;i*i<=x;i++)
		if (x%i==0) {
			cnt++;
			if (x/i!=i) cnt++;
		}
	return cnt==8&&x%2==1;
}
int main() {

	read(n);
	for (int i=1;i<=n;i++) if (solve(i)) ans++;
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