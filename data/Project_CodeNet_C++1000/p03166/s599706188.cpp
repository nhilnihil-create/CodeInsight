#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dfs(vector<int> edge[], int vertex, vector<int>& maximum){
    if(edge[vertex].size()==0) return 0;

    if(maximum[vertex]!=-1) return maximum[vertex];
    int ans = 0;
    for(int i=0;i<edge[vertex].size();i++){
        ans = max(ans, dfs(edge, edge[vertex][i], maximum));
    }
    maximum[vertex] = ans+1;
    return maximum[vertex];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> edge[100001];
    int v1, v2;
    vector<int> maximum(100001, -1);
    for(int i=0;i<m;i++){
        cin >> v1 >> v2;
        edge[v1].push_back(v2);
    }
    for(int i=1;i<=n;i++){
        if(maximum[i]==-1) maximum[i] = dfs(edge, i, maximum);
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, maximum[i]);
    cout << ans << endl;
    return 0;
}