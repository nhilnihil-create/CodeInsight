/*
知らなかったこと
"あるグラフが２部グラフであるためには,
グラフに奇数本の辺からなる閉路（奇サイクル）が含まれないことが
必要十分である"

長さ３に着目する理由

二部グラフでは同じグループの頂点間に辺は無い
奇数回の移動では同じグループの頂点にはたどり着けないため,辺が追加されることも無い

二部グラフでないならば, 任意の２頂点の間に奇数長のパスが存在する
・・・グラフが完全グラフになるまで辺を追加する

二部グラフを分けたときに同じグループの頂点同士の距離は必ず偶数になる
*/

// http://ronly.hatenablog.com/entry/2017/10/15/134854

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

using G = vector<vector<int>>;

G graph;

int color[101010];

bool dfs(int v, int c){
    
    color[v] = c;
    
    for (int i = 0; i < graph[v].size(); i++){
        
        if (color[graph[v][i]] == c) return false;
        if (color[graph[v][i]] == 0 && !dfs(graph[v][i],-c)) return false; //???????????? why !(dfs(-c)
    }
    
    return true;
}


int main(){
    long long n, m;
    cin >> n >> m;
    
    graph = G(n);
    
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        
        x--, y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    long long B = 0, W = 0;
    
    if(dfs(0,1)){
        
        for (int i = 0; i < n; i++){
            if (color[i] == 1) B++;
            else W++;
        }
        
        cout << B * W - m << endl;
    }
    else{
        cout << (n * (n-1)) / 2 - m << endl;
    }
}






