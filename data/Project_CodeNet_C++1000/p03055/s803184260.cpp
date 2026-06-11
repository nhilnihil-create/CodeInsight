#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> adjlist[n];
    for (int i = 1; i < n; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        --a, --b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int dist[n]; memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (q.size()){
        int u = q.front(); q.pop();
        for (auto v : adjlist[u]){
            if (dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++){
        if (dist[i] > dist[s]) s = i;
    }
    memset(dist,-1,sizeof(dist));
    q.push(s);
    dist[s] = 0;
    while (q.size()){
        int u = q.front(); q.pop();
        for (auto v : adjlist[u]){
            if (dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    int diameter = 0;
    for (int i = 0; i < n; i++){
        diameter = max(diameter,dist[i]);
    }
    //printf("%d",diameter);
    if (diameter%3 == 1){
        printf("Second");
    }
    else printf("First");

}
