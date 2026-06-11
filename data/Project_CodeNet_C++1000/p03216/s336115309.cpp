#include<bits/stdc++.h>
using namespace std;
const int MX=1048576,MB=20;
typedef long long LL;
int n,q,a[MX];
int readch(){
	char c=getchar();
	while(c==' '||c=='\n') c=getchar();
	if(c=='D') return 1;
	if(c=='M') return 2;
	if(c=='C') return 3;
}
struct data{
	int c0,c1;
	LL pr;
	void init(){
		c0=c1=0;
		pr=0ll;
	}
};
data merge(data A,data B){
	data R;
	R.c0=A.c0+B.c0;
	R.c1=A.c1+B.c1;
	R.pr=A.pr+B.pr+(LL)A.c0*(LL)B.c1;
	return R;
}
vector < data > t[5000005];
int lp[5000005],rp[5000005],AD;
void init(int p,int l=0,int r=MX-1){
	if(!l && !r) AD=p;
	lp[p]=l;
	rp[p]=r;
	t[p].resize(r-l+1);
	if(l==r){
		t[p][0].c0=(a[l]==2);
		t[p][0].c1=(a[l]==3);
		t[p][0].pr=0ll;
	}
	else{
		int M=(l+r)>>1,i;
		init((p<<1),l,M);
		init((p<<1|1),M+1,r);
		for(i=l;i<=r;++i){
			t[p][i-l].c0=(a[i]==2);
			t[p][i-l].c1=(a[i]==3);
			t[p][i-l].pr=0ll;
		}
		for(i=M-1;i>=l;--i){
			t[p][i-l]=merge(t[p][i-l],t[p][i-l+1]);
		}
		for(i=M+2;i<=r;++i){
			t[p][i-l]=merge(t[p][i-l-1],t[p][i-l]);
		}
	}
}
LL qry(int l,int r){
	r=min(r,n-1);
	LL ret=0ll;
	int ln=__builtin_clz(l+AD^r+AD)-11;
	int p=(1<<ln)-1&(l+AD>>MB-ln+1);
	return merge(t[p][l-lp[p]],t[p][r-lp[p]]).pr;
}
LL solve(int L){
	int i,j,k;
	LL ret=0ll;
	for(i=0;i<n;++i){
		if(a[i]==1){
			ret+=qry(i+1,i+L-1);
		}
	}
	return ret;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		a[i]=readch();
	}
	init(1);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&k);
		printf("%lld\n",solve(k));
	}
	return 0;
}