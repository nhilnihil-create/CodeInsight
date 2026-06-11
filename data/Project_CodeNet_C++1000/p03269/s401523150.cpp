#include<cstdio>
#include<vector>
struct Edge{
    int u,v;
    int c;
    Edge(int u,int v,int c):u(u),v(v),c(c){}
};
std::vector<Edge>g[105];
int bit[30];
int power[30];

int bitFactor(int u){
    int size = -1;
    while(u){
        bit[++size] = u%2;
        u /= 2;
    }
    power[0] = 1;
    for(int i = 1; i <= 23; i++) power[i] = power[i-1]*2;
    return size;
}

int main(){
    int u;
    scanf("%d",&u);
    u--;
    if(u==1){
        printf("%d %d\n",2,2);
        printf("%d %d %d\n",1,2,1);
        printf("%d %d %d\n",1,2,0);
    }
    else{
        int k = bitFactor(u);
        int n = k+1, m = 0;
        for(int i = 1; i <= n-1; i++){
            g[i].push_back(Edge(i,i+1,0));
            g[i].push_back(Edge(i,i+1,power[n-1-i]));
            m += 2;
        }
        //printf("m = %d\n",m);
        for(int i = k-1; i >= 0; i--){
            if(bit[i]==1){
                //printf("i = %d\n",i);
                int cost = 0;
                for(int j = k; j > i; j--) cost += bit[j]*power[j];
                g[1].push_back(Edge(1,n-i,cost));
                m++;
            }
        }
        g[1].push_back(Edge(1,n,u));
        m++;
        printf("%d %d\n",n,m);
        for(int i = 1; i <= n-1; i++){
            //printf("i = %d\n",i);
            for(int j = 0;j < (int)g[i].size(); j++){
                printf("%d %d %d\n",g[i][j].u,g[i][j].v,g[i][j].c);
            }
        }
    }
    return 0;
}
