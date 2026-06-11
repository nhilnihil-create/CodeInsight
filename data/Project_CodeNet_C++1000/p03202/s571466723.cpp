#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=200200,INF=1000010000;
int n,L,R,t,a[N];
struct ele{
	int l,r,w;
	ele(int _l=0,int _r=0,int _w=0){l=_l,r=_r,w=_w;}
}s[N];
bool chk(int S){
	int x=0,t=0,w,y;
	FOR(i,1,n){
		if(a[i]>x){s[++t]=ele(x+1,a[i]);x=a[i];continue;}
		x=a[i];
		while(s[t].l>x) t--;
		s[t].r=x;y=x+1;
		while(t && s[t].w==S-1) y=s[t--].l;
		if(!t) return 0;w=s[t].w;
		s[t].l<s[t].r?s[t].r--:t--;
		s[++t]=ele(y-1,y-1,w+1);
		if(y<=x) s[++t]=ele(y,x,0);
	}
	return 1;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	L=1;R=INF;
	while(L<R){
		int md=(L+R)>>1;
		chk(md)?R=md:L=md+1; 
	}
	cout<<L<<"\n";
}