#include <bits/stdc++.h>
using namespace std;
#define int long long
const int tx[]={0,0,1,-1};
const int ty[]={1,-1,0,0};
int getd(int a,int b,int x,int y){
	return abs(a-x)+abs(b-y);
}
char getc(int &a,int &b,int d,int x,int y){
	int Mn=2e9,op=-1;
	for (int i=0;i<4;i++){
		int xx=a+tx[i]*d,yy=b+ty[i]*d;
		int dis=getd(xx,yy,x,y);
		if (dis<Mn) {Mn=dis; op=i;}
	}
	a=a+tx[op]*d; b=b+ty[op]*d;
	if (op==0) return 'U';
	if (op==1) return 'D';
	if (op==2) return 'R';
	return 'L';
}
int x[1111],y[1111],d[222],cnt[2],m;
signed main(){
	int T; scanf("%lld",&T);
	for (int i=1;i<=T;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		cnt[(x[i]+y[i])%2]++;
	}
	if (cnt[1]&& cnt[0]) return puts("-1"),0;
	for (int i=0;i<=30;i++) d[i+1]=1<<(30-i);
	if (cnt[0]) d[32]=1,m=32; else m=31;
	printf("%lld\n",m);
	for (int i=1;i<=m;i++) printf("%lld ",d[i]); puts("");
	for (int i=1;i<=T;i++){
		int a=0,b=0;
		for (int j=1;j<=m;j++)
			putchar(getc(a,b,d[j],x[i],y[i]));
		puts("");
	}
	return 0;
}
	