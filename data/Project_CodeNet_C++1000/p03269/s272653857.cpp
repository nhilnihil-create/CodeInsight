#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int l,cnt=0,m=0;
int head[50];
struct node{
	int to,nxt,cap;
}e[1000010];
void add(int u,int v,int c){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;e[cnt].cap=c;
}
int low(int x){
	return x&-x;
}
int main(){
	scanf("%d",&l);
	int i,j;
	for(i=2;i<=19;++i){
		add(i,i+1,0);add(i,i+1,(1<<(20-i-1)));m+=2;
	}
	while(l){
		int x=log2(low(l));l^=low(l);
		if(x==19){add(1,2,0);add(1,2,1<<18);m+=2;}
		else{add(1,20-x,l);m++;}
	}
	printf("%d %d\n",20,m);
	for(i=1;i<=20;++i){
		for(j=head[i];j;j=e[j].nxt){
			printf("%d %d %d\n",i,e[j].to,e[j].cap);
		}
	}
	return 0;
}