#include<iostream>
#include <algorithm>
#include<cstdio>
#include<string>
#include<math.h>
#include<vector>
#include <queue>
#include <bits/stdc++.h>
#include <map>
#include <cmath>
#include <cctype>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
using namespace std;
typedef vector<vector<char>> field_t;

typedef pair<int, int> point_t;
vector<vector<pair<int,int>>> z(100010);
int ans[100010];
bool used[100010];
void dfs(int v, int w){
    if(w%2==0){
        ans[v]=1;
    }else{
        ans[v]=0;
    }
    for(auto t:z[v]){
        if(!used[t.first]){
            used[t.first]=true;
            dfs(t.first,t.second+w);
        }
    }
}

int main()
{
    int N,i;
    cin >> N;
    vector<int> x(N); 
    rep(i,N-1){
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        z[u].push_back(make_pair(v,w));
        z[v].push_back(make_pair(u,w));
    }
    dfs(0,0);
    rep(i,N){
        cout << ans[i] <<endl;
    }
    return 0;
}