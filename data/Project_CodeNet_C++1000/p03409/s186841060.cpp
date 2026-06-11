/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+5;

int n;
int vis[N];
int taken[N];
pair < int , int > red[N] , blue[N];

bool dfs(int u){
    if(vis[u])
        return false;
    vis[u] = true;
    for(int i = 1; i <= n; i++){
        if(red[u].first < blue[i].first && red[u].second < blue[i].second){
            if(!taken[i] || dfs(taken[i])){
                taken[i] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++){
        int x , y;
        scanf("%d%d" , &x , &y);
        red[i] = {x , y};
    }
    for(int i = 1; i <= n; i++){
        int x , y;
        scanf("%d%d" , &x , &y);
        blue[i] = {x , y};
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(vis , 0 , sizeof vis);
        if(dfs(i)){
            ans++;
        }
    }
    printf("%d\n" , ans);
}
