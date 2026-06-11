#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
#define Maxn 1005
int x[Maxn],y[Maxn];
bool flag=false;
bool ap[2];
int Move[Maxn][45];
bool in(int u,int d){
	ll dis=(ll)abs(x[u])+(ll)abs(y[u]);
	int up=((1<<d)-1)*2+1;
	return dis<=up;
}
void MMove(int u,int d){
	if(d==0){
		if(x[u]==1&&y[u]==0)Move[u][++Move[u][0]]=0;
		if(x[u]==-1&&y[u]==0)Move[u][++Move[u][0]]=1;
		if(x[u]==0&&y[u]==1)Move[u][++Move[u][0]]=2;
		if(x[u]==0&&y[u]==-1)Move[u][++Move[u][0]]=3;
		return;
	}
	x[u]-=(1<<d);
	if(in(u,d-1)){
		Move[u][++Move[u][0]]=0;
		return;
	}
	x[u]+=(1<<d);
	x[u]+=(1<<d);
	if(in(u,d-1)){
		Move[u][++Move[u][0]]=1;
		return;
	}
	x[u]-=(1<<d);
	y[u]-=(1<<d);
	if(in(u,d-1)){
		Move[u][++Move[u][0]]=2;
		return;
    }
	y[u]+=(1<<d);
	y[u]+=(1<<d);
	if(in(u,d-1)){
		Move[u][++Move[u][0]]=3;
		return;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%d%d",&x[1],&y[1]);
	int now;
	now=((x[1]+y[1])%2+2)%2;
	ap[now]=true;
	for(int i=2;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		now=((x[i]+y[i])%2+2)%2;
		if(!ap[now]){
			puts("-1");
			return 0;
		}
	}
	if(ap[0]){
		flag=true;
		for(int i=1;i<=n;++i)x[i]--;
	}
    int all;
    for(all=0;all<=30;++all){
    	bool hehe=true;
    	for(int i=1;i<=n;++i)
    		if(!in(i,all)){
    			hehe=false;
    			break;
    		}
    	if(hehe)break;
    }
    if(flag)printf("%d\n",all+2);
    else printf("%d\n",all+1);
    for(int i=all;i>=0;--i){
    	for(int j=1;j<=n;++j)MMove(j,i);
    }
    if(flag)printf("1 ");
    for(int i=0;i<=all;++i)printf("%d ",1<<i);
    puts("");
    for(int i=1;i<=n;++i){
    	if(flag)printf("R");
    	for(int j=Move[i][0];j>=1;--j){
    		if(Move[i][j]==0)printf("R");
    		if(Move[i][j]==1)printf("L");
    		if(Move[i][j]==2)printf("U");
    		if(Move[i][j]==3)printf("D");
    	}
    	puts("");
    }
    return 0;
}