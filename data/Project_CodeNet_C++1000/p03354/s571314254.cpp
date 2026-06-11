/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n;
int m;
int ar[N];
int pos[N];
int parent[N];

int getP(int u){
    if(parent[u] == u)
        return u;
    return parent[u] = getP(parent[u]);
}

void join(int u , int v){
    u = getP(u);
    v = getP(v);
    parent[v] = u;
}

int main(){
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= n; i++){
        scanf("%d" , &ar[i]);
        pos[ar[i]] = i;
        parent[i] = i;
    }
    for(int i = 1; i <= m; i++){
        int u , v;
        scanf("%d%d" , &u , &v);
        join(u , v);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += getP(pos[ar[i]]) == getP(ar[i]);
    }
    printf("%d\n" , ans);
}