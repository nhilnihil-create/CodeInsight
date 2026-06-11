#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[maxn],t[maxn];
map<long long,char>v;
int gcd(int x,int y) {
	while(y^=x^=y^=x%=y);
	return x;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",s,t);
	for(int i=0;i<n;i++)v[1ll*i*m]=s[i];
	for(int i=0;i<m;i++)
		if(v[1ll*i*n]&&v[1ll*i*n]!=t[i]) {
			puts("-1");
			return 0;
		}
	printf("%lld\n",1ll*n*m/gcd(n,m));
	return 0;
}