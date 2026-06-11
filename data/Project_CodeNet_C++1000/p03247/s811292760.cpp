#include<bits/stdc++.h>
#define rep(X,A,B) for(int X=A;X<=B;X++)
#define tep(X,A,B) for(int X=A;X>=B;X--)
#define LL long long
#define DB double
const int N=400010;
const int M=800010;
const int maxn=30;
using namespace std;

int n;
char c[2][2];
int p[2],g[2];

struct nn{
	int x,y;
}a[N];

void READ(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i].x,&a[i].y);
		g[abs(a[i].x+a[i].y)%2]++;
	}
}

void PRT(int x){
	if(!x){
		printf("0\n");
		return;
	}
	int pos=0,flp[10];
	while(x)flp[++pos]=x%2,x/=2;
	tep(i,pos,1)printf("%d",flp[i]);
	printf("\n");
}

void PRT(int x,int y){
	c[0][0]='R';c[0][1]='L';
	c[1][0]='U';c[1][1]='D';
	if(x<0)x=-x,swap(c[0][0],c[0][1]);
	if(y<0)y=-y,swap(c[1][0],c[1][1]);
	int flg=0;
	p[0]=0,p[1]=0;
	tep(i,maxn,0){
		if(x<y)swap(x,y),flg^=1;
		printf("%c",c[flg][p[flg]]);
		if(!((x>>i)&1))p[flg]^=1,x=(1<<i)-x;
		else x^=(1<<i);
	}
	if(g[0])printf("R");
	printf("\n");
}

int SOLVE(){
	if(g[1]*g[0]!=0)return 0;
	printf("%d\n",maxn+1+(g[0]!=0));
	tep(i,maxn,0)printf("%d ",(1<<i));
	if(g[0]!=0){
		rep(i,1,n)a[i].x--;
		printf("1");
	}
	printf("\n");
	//---
	rep(i,1,n)PRT(a[i].x,a[i].y);
	return 1;
}

int main(){
	READ();
	if(!SOLVE())printf("-1\n");
	return 0;
}