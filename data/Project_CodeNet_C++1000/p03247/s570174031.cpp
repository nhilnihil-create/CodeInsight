#include<stdio.h>
typedef long long ll;
ll abs(ll x){return x>0?x:-x;}
const int go[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int x[1010],y[1010],c[2],m;
char s[40];
void work(ll x,ll y){
	int i,j;
	ll tx,ty;
	for(i=m-1;i>=0;i--){
		for(j=0;j<4;j++){
			tx=x+go[j][0]*(1<<i);
			ty=y+go[j][1]*(1<<i);
			if(abs(tx)+abs(ty)<=(1<<i)-1){
				s[i]="DULR"[j];
				x=tx;
				y=ty;
				break;
			}
		}
	}
	printf("%s",s);
}
int main(){
	int n,i,ad;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		c[(x[i]^y[i])&1]++;
	}
	if(c[0]&&c[1]){
		puts("-1");
		return 0;
	}
	ad=0;
	if(c[0]){
		for(i=1;i<=n;i++)x[i]++;
		ad=1;
	}
	m=31;
	printf("%d\n",m+ad);
	for(i=1;i<=m;i++)printf("%d ",1<<(i-1));
	if(ad)putchar('1');
	putchar('\n');
	for(i=1;i<=n;i++){
		work(x[i],y[i]);
		if(ad)putchar('L');
		putchar('\n');
	}
}