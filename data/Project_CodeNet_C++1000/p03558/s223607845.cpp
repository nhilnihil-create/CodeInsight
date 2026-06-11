# include "queue"
# include "cstdio"
# include "cstring" 

using namespace std; 

int k,ne,h[100004];

struct edge{
    int to,nt,w;
}e[500004];

queue<int>q;

int dis[100004];

void add(int u,int v,int w){
     e[++ne].to = v;e[ne].nt = h[u];
     e[ne].w=w;
     h[u]=ne;
}
int main(){
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        add(i,(i+1)%k,1);
        add(i,(i*10)%k,0);
    }
    q.push(1);
    memset(dis,127/3,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=h[x];i;i=e[i].nt){
            if(dis[e[i].to]>dis[x]+e[i].w){
            	dis[e[i].to]=dis[x]+e[i].w;
            	q.push(e[i].to);
            }
        }
    }
    printf("%d\n",dis[0]+1);
    return 0;
} 