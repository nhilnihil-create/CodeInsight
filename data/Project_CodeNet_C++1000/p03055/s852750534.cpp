#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> bfs(const vector<vector<int>>& g, int start){
    const int n = g.size();
    vector<int> step(n, 1000000007);
    queue<int> qu; qu.push(start);
    step[start] = 0;
    pair<int,int> res = make_pair(start, 0);
    while(!qu.empty()){
        int p = qu.front(); qu.pop();
        for(auto& dst : g[p]){
            if(step[p] + 1 < step[dst]){
                step[dst] = step[p] + 1;
                qu.push(dst);
                if(res.second < step[dst]){
                    res = make_pair(dst, step[dst]);
                }
            }
        }
    }
    return res;
}

int main(){
    int N;
    while(cin >> N){
        vector<vector<int>> g(N);
        for(int i=0;i<N-1;i++){
            int a, b; cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << (bfs(g, bfs(g, 0).first).second % 3 == 1 ? "Second" : "First") << endl;
    }
}