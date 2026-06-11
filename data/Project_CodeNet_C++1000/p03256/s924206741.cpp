#include<stdio.h>
int h[200010],to[400010],nex[400010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
char s[200010];
int c[200010],d[200010][2],st[200010];
bool del[200010],ins[200010];
int main(){
	int n,m,i,x,y;
	scanf("%d%d%s",&n,&m,s+1);
	for(i=1;i<=n;i++)c[i]=s[i]=='B';
	while(m--){
		scanf("%d%d",&x,&y);
		d[x][c[y]]++;
		add(x,y);
		if(x!=y){
			d[y][c[x]]++;
			add(y,x);
		}
	}
	M=0;
	for(i=1;i<=n;i++){
		if(d[i][0]==0||d[i][1]==0)ins[st[++M]=i]=1;
	}
	while(M){
		del[x=st[M--]]=1;
		ins[x]=0;
		for(i=h[x];i;i=nex[i]){
			if(!del[to[i]]){
				d[to[i]][c[x]]--;
				if((d[to[i]][0]==0||d[to[i]][1]==0)&&!ins[to[i]])st[++M]=to[i];
			}
		}
	}
	for(i=1;i<=n;i++){
		if(!del[i]){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}