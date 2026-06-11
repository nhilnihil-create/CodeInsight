#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const long long inf = 1e10;
const long long mod = 1e9+7;

typedef vector<vector<int> > G;
G graph;

int color[100050];

bool dfs(int u, int c){
    color[u] = c;
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        if(color[v] == c){
            return false;
        }
        if(color[v] == 0 && !dfs(v, -c) ){
            return false;
        }
    }   
    return true;
}

int main(void){
    long long n, m;
    cin >> n >> m;
    graph = G(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    long long B=0, W=0;
    if(dfs(0, 1)){
        for(int i=0; i<n; i++){
            if(color[i] == 1){
                B++;
            }else if(color[i] == -1){
                W++;
            }
        }
        cout << B*W - m << endl;
    }else{
        cout << ( (n*(n-1)) /2) - m << endl;
    }
    
    return 0;
}