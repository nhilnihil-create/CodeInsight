#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define rg register
#define ll long long
#define LDB long double
#define ull unsigned long long
#define view(i,x) for(rg int i=hd[x];i!=-1;i=e[i].nt)
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
using namespace std;

const int maxn=2*1e5+5;
int h,w,n,tt,a[maxn];
struct edd{
	int x,y;
}p[maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

int main(){
	h=rd(); w=rd(); n=rd(); int x,y,ansq=h;
	memset(a,63,sizeof(a));
	go(i,n+1,1){
		x=rd(); y=rd(); if(x < y) continue;
		p[++tt].x=x; p[tt].y=y;
		a[x-y]=min(a[x-y],x);
	}
	go(i,h+1,1){
		if(a[i] > a[i-1]) continue;
		if(a[i]-1 < ansq) ansq=a[i]-1;
	}
	printf("%d",ansq);
	return 0;
}//Faze
