#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
const int N=1005;
const ll inf=1e18;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};
const char ch[4]={'R','L','D','U'};
int n,x[N],y[N],odd,even,a[N];
int main(){
	scanf("%d",&n);
	rep (i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		if ((x[i]+y[i])&1) odd++; else even++;
	}
	if (odd&&even) return puts("-1"),0;
	puts(even?"32":"31");
	for (int i=30;i+1;i--) printf("%d ",a[++*a]=(1<<i));
	if (even) a[++*a]=1,puts("1"); else puts("");
	rep (t,1,n){
		ll nx=0,ny=0,px,py,Min; int d;
		rep (i,1,*a){
			Min=inf;
			rep (k,0,3){
				px=nx+dx[k]*a[i],py=ny+dy[k]*a[i];
				if (abs(px-x[t])+abs(py-y[t])<Min) Min=abs(px-x[t])+abs(py-y[t]),d=k;
			}
			nx+=dx[d]*a[i],ny+=dy[d]*a[i];
			printf("%c",ch[d]);
		}
		puts("");
	}
	return 0;
}