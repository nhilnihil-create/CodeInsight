#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
 
void dfs1(int &u, int nowcost, int &dis, int node, vector<bool> &used, vector<vector<pair<int, int> > > &adj){
    used[node] = true;
    if(dis < nowcost){
        dis = nowcost;
        u = node;
    }
    //cout << node << " " << nowcost << endl;
    for(int i = 0; i < (int)adj[node].size(); i++){
        //cout << "ok" << endl;
        int to = adj[node][i].first;
        int cost = adj[node][i].second;
        if(!used[to]){
            dfs1(u, nowcost + cost, dis, to, used, adj);
        }
    }    
}
 
void dfs2(int nowcost, int &dis, int node, vector<bool> &used, vector<vector<pair<int, int> > > &adj){
    used[node] = true;
    dis = max(dis, nowcost);
    //cout << node << " " << nowcost << endl;
    for(int i = 0; i < (int)adj[node].size(); i++){
        //cout << "ok" << endl;
        int to = adj[node][i].first;
        int cost = adj[node][i].second;
        if(!used[to]){
            dfs2(nowcost + cost, dis, to, used, adj);
        }
    }    
}
 
int main(){
    int n; cin >> n;
    if(n == 1) return !printf("First\n");
    vector<vector<pair<int, int> > > adj(n);
    for(int i = 0; i < n - 1; i++){
        int a, b, c; cin >> a >> b;
        a--;
        b--;
        adj[a].push_back({b, 1});
        adj[b].push_back({a, 1});
    }
 
    int u;
    int dis = 0;
    vector<bool> used(n, false);
    dfs1(u, 0, dis, 0, used, adj);
    for(int i = 0; i < n; i++) used[i] = false;
    dis = 0;
    dfs2(0, dis, u, used, adj);
    if(dis % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}
