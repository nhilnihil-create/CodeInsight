#include<bits/stdc++.h>
using namespace std;

vector<int> ans(1000000);
int n;
int checked= 1;
void dfs(int i,int pre,int color,vector<vector<vector<int>>> &rel){
    if(checked== n) return ;
    for (int j = 0; j < rel[i].size(); j++)
    {
        if(rel[i][j][0] != pre){
            checked ++ ;
            if(rel[i][j][1] == 1) color = 1-color;
            ans[rel[i][j][0]] = color;
            dfs(rel[i][j][0],i,color,rel);
            if(rel[i][j][1] == 1) color = 1-color;
        }
    }
    
}


int main(){
    cin >> n;
    vector<int> u(n-1) , v(n-1), w(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    vector<vector<vector<int>>> rel(n);
    for (int i = 0; i < n-1; i++)
    {
            rel[u[i]-1].push_back({v[i]-1, w[i]%2});
            rel[v[i]-1].push_back({u[i]-1, w[i]%2});
    }
    dfs(0,-1,0,rel);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}