#include<bits/stdc++.h>
using namespace std;

long long int nax=1e5+5;
vector<vector<int>>edge(nax);
vector<int>degree(nax);
vector<bool>visited(nax,false);
vector<int>dp(nax,0);
void recur(int a){
    visited[a]=true;
    for(int i=0;i<edge[a].size();i++)
    {
        int k=edge[a][i];
        dp[k]=((dp[k]>dp[a]+1)?dp[k]:dp[a]+1);
        degree[k]--;
        if(degree[k]==0){
            recur(k);
        }
    }
    
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        edge[a].push_back(b);
        degree[b]++;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&&degree[i]==0){
            recur(i);
        }
    }
    int nax=0;
    for(int i:dp){
        nax=max(nax,i);
    }
    cout<<nax;
}