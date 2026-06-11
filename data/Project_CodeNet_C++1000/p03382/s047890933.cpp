#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

typedef long double db;
const int N=200005;

std:: set <db> set;

int a[N],prt1,prt2;
db fac[N],ans=-1;

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void upd(int n,int m) {
	if (n<m) return ;
	if (m==0) {
		if (fac[1]>ans) {
			ans=fac[1];
			prt1=n,prt2=m;
		}
		return ;
	}
	if (fac[n]-fac[m]-fac[n-m]>ans) {
		ans=fac[n]-fac[m]-fac[n-m];
		prt1=n,prt2=m;
	}
}

void solve(int x) {
	db tmp=0.5*x;
	int wjp=-1,lxf=-1;
	set.insert(tmp);
	std:: set <db>:: iterator pos=set.find(tmp);
	if (pos!=set.begin()) {
		pos--; wjp=*pos; pos++;
	}
	pos++;
	if (pos!=set.end()) lxf=*pos;
	pos--;
	if (wjp>=0) upd(x,wjp);
	if (lxf>=0) upd(x,lxf);
	set.erase(pos);
}

int main(void) {
	// rep(i,1,N-1) fac[i]=fac[i-1]+log(i);
	int n=read();
	db mn=1000000000;
	rep(i,1,n) a[i]=read();
	std:: sort(a+1,a+n+1);
	rep(i,1,n-1) {
		if (fabs(a[i]-0.5*a[n])<mn) {
			mn=fabs(a[i]-0.5*a[n]);
			prt1=i;
		}
	}
/*	rep(i,1,n) {
		solve(a[i]);
		set.insert(a[i]);
	}
	printf("%d %d\n", prt1,prt2);*/
	printf("%d %d\n", a[n],a[prt1]);
	return 0;
}