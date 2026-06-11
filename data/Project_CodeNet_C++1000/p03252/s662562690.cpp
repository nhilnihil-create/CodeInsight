#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,a[30],b[30],x,y;
char s[maxn],t[maxn];
int main() {
	
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) {
		x=s[i]-'a'+1,y=t[i]-'a'+1;
		if (!a[x]) a[x]=y;
		else if (a[x]!=y) { printf("No\n"); return 0; }
		if (!b[y]) b[y]=x;
		else if (b[y]!=x) { printf("No\n"); return 0; }
	}
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