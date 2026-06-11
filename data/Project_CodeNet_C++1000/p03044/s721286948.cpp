//
//  main.cpp
//  D
//
//  Created by 曾憲揚 on 2020/9/7.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
typedef pair<int, bool> pib;
bool color[N];
vector<pib> e[N];

#define fr first
#define sc second

void dfs(int p, int cur){
    for(auto pa: e[cur]){
        if(pa.fr!=p){
            color[pa.fr]=color[cur]^pa.sc;
            dfs(cur, pa.fr);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n; cin>>n;
    for(int i=1; i<n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        e[u].push_back({v, w%2});
        e[v].push_back({u, w%2});
    }
    
    color[1]=0;
    dfs(0, 1);
    for(int i=1; i<=n; i++)
        cout<<color[i]<<endl;
    return 0;
}
