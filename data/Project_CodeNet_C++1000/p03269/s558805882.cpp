#include <stdio.h>
#include <string.h>
#define MN 20
#define MM 60
int n=20,m,l,tot,size[MN+5];
int hd[MN+5],to[MM+5],val[MM+5],nxt[MM+5];
void add(int u,int v,int w){
	to[m]=v,val[m]=w,nxt[m]=hd[u];
	hd[u]=m++;
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d",&l);
	for(int i=2;i<20;i++){
		add(i,i+1,0);
		add(i,i+1,1<<(19-i));
		size[i]=(1<<(20-i));
	}size[20]=1;
	for(int i=2;i<=n;i++)
		while(l-tot>=size[i]){
			add(1,i,tot);
			tot+=size[i];
		}
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		for(int j=hd[i];~j;j=nxt[j])
			printf("%d %d %d\n",i,to[j],val[j]);
}