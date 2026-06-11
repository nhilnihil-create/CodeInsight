#include <bits/stdc++.h>

const int N=int(2e5)+10;
int H,W,n,sr,sc,suf[N];
char s[N],t[N];
bool check(char a,char b,int dis,int lim) {
	suf[n+1]=0;
	int sum=0;
	for (int i=n;i>=1;--i) {
		suf[i]=suf[i+1];
		if (s[i]==b) {
			suf[i]=std::min(suf[i],sum-1);
			--sum;
		}
		if (t[i]==a) {
			if (sum<0) ++sum;
		}
	}
	int pos=dis;
	for (int i=1;i<=n;++i) {
		if (s[i]==a) ++pos;
		if (pos>lim) return 0;
		if (t[i]==b) {
			if (pos-1+suf[i+1]>=1) --pos;
		}
	}
	return 1;
}
int main() {
	scanf("%d%d%d%d%d",&H,&W,&n,&sr,&sc);
	scanf("%s",s+1);
	scanf("%s",t+1);
	if (!check('D','U',sr,H)||!check('U','D',H-sr+1,H)||!check('R','L',sc,W)||!check('L','R',W+1-sc,W))
		puts("NO");
	else puts("YES");
}
