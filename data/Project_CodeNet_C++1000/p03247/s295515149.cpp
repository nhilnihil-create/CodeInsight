#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1010,TOP=30;
int rec[N][2],d[N];
int n,m;
int Abs(int x){return x<0?-x:x;}
bool firstcheck(){
	for (int i=2;i<=n;++i)
		if ((Abs(rec[i][0]+rec[i][1])%2)^(Abs(rec[1][0]+rec[1][1])%2))
			return false;
	return true;
}
void solve(int x,int y){
	int val;
	for (int i=m;i>=1;--i){
		val=d[i];
		if (Abs(x)>=val){
			if (x<0) x+=val,printf("L");
			else x-=val,printf("R");
		}
		else if (Abs(y)>=val){
			if (y<0) y+=val,printf("D");
			else y-=val,printf("U");
		}
		else{
			if (Abs(x)>Abs(y)){
				if (x<0) x+=val,printf("L");
				else x-=val,printf("R");
			}
			else{
				if (y<0) y+=val,printf("D");
				else y-=val,printf("U");
			}
		}
	}
	printf("\n");
	if (x||y) printf("fish qwq\n");
}
void get_ans(){
	int flag=(Abs(rec[1][0]+rec[1][1])%2)^1;
	m=TOP+1+flag;
	printf("%d\n",m);
	int tot=m;
	for (int i=TOP;i>=0;--i,--tot) printf("%d ",1<<i),d[tot]=1<<i;
	if (flag) printf("1"),d[tot]=1;
	printf("\n");
	for (int i=1;i<=n;++i)
		solve(rec[i][0],rec[i][1]);
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&rec[i][0],&rec[i][1]);	
	if (!firstcheck()) printf("-1\n");
	else{
		get_ans();
	}
}
