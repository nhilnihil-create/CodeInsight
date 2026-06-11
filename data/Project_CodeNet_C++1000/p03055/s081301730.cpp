#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int lli;

void dfs(int v, vector<int> &dist, vector<vector<int> > &g){
    for(int next: g[v]){
        if(dist[next] == -1){
            dist[next] = dist[v]+1;
            dfs(next, dist, g);
        }
    }
}
int diameter(vector<vector<int> > &g){
    int n = g.size();
    vector<int> d(n, -1);
    d[0] = 0;
    dfs(0, d, g);
    int idx = max_element(d.begin(), d.end()) -d.begin();
    d = vector<int>(n, -1);
    d[idx] = 0;
    dfs(idx, d, g);
    return *max_element(d.begin(), d.end());
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int d = diameter(adj);
    if(d%3==1){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
    return 0;
}