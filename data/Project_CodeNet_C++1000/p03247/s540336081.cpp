#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=1000 +117;
const int MM= +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
struct node{
	LL x,y;
	node(LL x_=0,LL y_=0){
		x=x_,y=y_;
	}
}a[NN]={};
LL ab(LL x){
	return x>0?x:-x;
}
LL dis(node a,node b){
	return ab(a.x-b.x)+ab(a.y-b.y);
}
int c[2];
int pre[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char op[4]={'L','R','D','U'};
void solve(node tar){
	node now=node(0,0);
	int range=0x7fffffff;
	for(int i=30;i>=0;--i){
		int st=1<<i;
		range-=st;
		for(int j=0;j<4;++j){
			node xt=node(now.x+st*pre[j][0],now.y+st*pre[j][1]);
			if(dis(xt,tar)<=range){
				putchar(op[j]);
				now=xt;
				break;
			}
		}
	}
	putchar('\n');
}
int main(){
	//open();
	n=read();
	for(int i=1;i<=n;++i){
		a[i].x=read();
		a[i].y=read();
		c[(a[i].x^a[i].y)&1]=1;
	}
	if(c[0]&&c[1]){
		printf("-1\n");
		return 0;
	}
	if(c[0]){
		m=32;
	}
	else m=31;
	printf("%d\n",m);
	if(c[0]){
		printf("%d ",1);
	}
	for(int i=30;i>=0;--i){
		printf("%d ",1<<i);
	}
	putchar('\n');
	for(int i=1;i<=n;++i){
		if(c[0]){
			putchar('L');
			a[i].x+=1;
		}
		solve(a[i]);
	}
	close();
	return 0;
}