#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
string s[110];
int main() {

	read(n);
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<n;i++) if (s[i][(int)s[i].size()-1]!=s[i+1][0]) { printf("No\n"); return 0; }
	sort(s+1,s+n+1);
	for (int i=1;i<n;i++) if (s[i]==s[i+1]) { printf("No\n"); return 0; }
	printf("Yes\n");
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