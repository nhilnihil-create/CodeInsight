#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=2e5+50;
int n;
LL X, ans=0x3f3f3f3f3f3f3f3f, a[N], s[N];
int main() {
	n=rd(); X=rd();
	for(int i=1;i<=n;i++) s[i]=(a[i]=rd())+s[i-1];
	for(int k=1;k<=n;++k) {
		LL sum=0;
		for(int j=1,l,r=n;r && sum+k*X<ans;++j, r=l-1) {
			l=max(r-k+1,1);
			sum+=(j==1 ? 5 : 2*j+1)*(s[r]-s[l-1]);
		} ans=min(ans,sum+k*X);
	}
	cout<<ans+n*X<<'\n';
}