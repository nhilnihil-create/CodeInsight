#include <bits/stdc++.h>
using namespace std;

vector<int> AdjList[200005];
int dist[200005];

void bfs(int s){
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: AdjList[u]){
            if(dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
                //printf("debug: %d %d\n", v, dist[v]);
            }
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N-1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        //printf("%d %d\n", a, b);
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }

    bfs(1);
    int maxDist = 0;
    int indx = 0;
    for(int i = 1; i <= N; i ++){
        if(dist[i] > maxDist){
            maxDist = dist[i];
            indx = i;
        }
    }
    bfs(indx);
    maxDist = 0;
    for(int i = 1; i <= N; i ++){
        if(dist[i] > maxDist){
            maxDist = dist[i];
        }
    }
    if(maxDist%3 == 1){
        printf("Second");
    }else{
        printf("First");
    }
}


