#include <bits/stdc++.h>
using namespace std;
char S[120000]; int n,a[3],x,y;
int main(){
	scanf("%s",S); n=strlen(S);
	for (int i=0;i<n;++i) ++a[S[i]-'a'],x=max(x,a[S[i]-'a']);
	if (x-a[0]>1||x-a[1]>1||x-a[2]>1) puts("NO"); else puts("YES");
	return 0;
}