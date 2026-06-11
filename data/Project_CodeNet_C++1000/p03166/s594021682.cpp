//
//  main.cpp
//  G- Longest Path
//
//  Created by dz2701 on 8/26/20.
//  Copyright © 2020 dz2701. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int N, M, dp[MAX]; //max route to get to i
int k[MAX];

vector<int>adj[MAX];


int main(){
    cin >> N >> M;
    for(int i=1;i<=M;++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); //only go from a to b
        k[b]++;
    }
    
    queue<int>q;
    for(int i=1;i<=N;i++){
        if(!k[i]){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        for(auto i : adj[f]){
            k[i]--;
            dp[i] = max(dp[i], dp[f]+1);
            if(k[i]==0)q.push(i);
        }
    }
    
    int ans = -1e9;
    for(int i=1;i<=N;i++){
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    return 0;
    
}
