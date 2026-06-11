//
//  main.cpp
//  E
//
//  Created by 曾憲揚 on 2020/9/7.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

vector<int> e[N];

bool vis[N];
int dsus=0;

void dfs(int cur){
    vis[cur]=1;
    dsus++;
    for(int nxt:e[cur])
        if(!vis[nxt])
            dfs(nxt);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x, y, z; cin>>x>>y>>z;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    
    int ans = n;
    
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dsus=0;
            dfs(i);
            ans-=(dsus-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
