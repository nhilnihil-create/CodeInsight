#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()

template <typename T> bool chmax(T &a, const T b){if(a < b){a = b;return true;}return false;}

vector<int> bfs(int top, vector<vector<int>>& graph)
{
    int i,j;
    queue<int> que;
    int n = graph.size();
    vector<int> vdis(n,-1);
    vdis.at(top) = 0;
    que.emplace(top);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        int dist = vdis.at(now);
        for(i = 0;i < graph.at(now).size();++i){
            int next = graph.at(now).at(i);
            if(vdis.at(next) == -1){
                vdis.at(next) = dist+1;
                que.emplace(next);
            }
        }
    }
    return vdis;
}

int main()
{
    int i,j;
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        --a;    --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> v = bfs(0, graph);
    int p = -1;
    int num = -1;
    rep(i,n){
        if(chmax(num, v[i])) p = i;
    }
    vector<int> u = bfs(p, graph);
    int ans = -1;
    rep(i,n) chmax(ans, u[i]);
    if(ans%3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;

    return 0;
}