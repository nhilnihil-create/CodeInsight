#include<cstdio>
int vis[10];
int record[10];
int edge[5][5];

int find = 0;

void dfs(int p,int n){
    if(p==n+1){
        int ok = 1;
        for(int i = 1; i <= 3; i++){
            if(edge[record[i]][record[i+1]]==0) ok = 0;
        }
        find |= ok;
    }
    else{
        for(int i = 1; i <= 4; i++){
            if(!vis[i]){
                vis[i] = 1, record[p] = i;
                dfs(p+1,n);
                vis[i] = 0;
            }
        }
    }
}

int main(){
    for(int i = 0; i < 3; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a][b] = edge[b][a] = 1;
    }   
    dfs(1,4);
    if(find==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
