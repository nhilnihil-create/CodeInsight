//http://tutuz.hateblo.jp/entry/2018/10/28/085507
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,m,cnt;

vector<int>a[1000];

int main() {
	scanf("%d",&n);
	
	for(int i=1;i*(i-1)<=2*n;i++) if(i*(i-1)==n*2) m=i;
	
	if(!m) {
		puts("No");return 0;
	}
	
	puts("Yes");printf("%d\n",m);
	
	for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++) cnt++,a[i].pb(cnt),a[j].pb(cnt);
	
	for(int i=1;i<=m;i++) {
		printf("%d ",a[i].size());

		for(int j=0;j<a[i].size();j++) printf("%d%c",a[i][j],j==a[i].size()-1?'\n':' ');
	}
	
	return 0;
}
