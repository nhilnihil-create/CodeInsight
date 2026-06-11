#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<cstring>
#include<functional>
#include<bitset>
using namespace std;
typedef	long long int ll;

bool color[100001]; //v_maxは最大頂点数
int d[100001]; //最初に訪問した時間
int f[100001]; //探索し終えた時間
int t = 0; //時間
vector< pair<int, int> > g[100001]; //隣接リスト
int x[100001]; //人の位置

bool dfs(int u){
    color[u] = 1;
    d[u] = ++t;
    for(int i = 0; i < g[u].size(); i++){
        if(x[g[u][i].first] == 2000000001){
            x[g[u][i].first] = x[u] + g[u][i].second;
        }
        else if(x[g[u][i].first] != x[u] + g[u][i].second){
            return 0;
        }
        if(color[g[u][i].first] == 0){
            if(dfs(g[u][i].first) == 0) return 0;
        }
    }
    f[u] = ++t;
    return 1;
}

int main(){
    int n, m, l, r, d;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> l >> r >> d;
        g[l].push_back(make_pair(r,d));
        g[r].push_back(make_pair(l, -d));
    }
    memset(color, 0, sizeof(color));
    for(int i = 1; i <= n; i++){
        x[i] = 2000000001;
    }
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            x[i] = 0;
            bool res = dfs(i);
            if(!res){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}