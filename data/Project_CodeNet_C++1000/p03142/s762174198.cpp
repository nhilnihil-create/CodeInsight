#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TS{
    int n;
    vector< vector<int> > edge;
    vector<int> res;

    void init(int size){
        n = size;
        edge.assign(n, vector<int>());
    }

    void add_edge(int from, int to){
        if(from < 0 || from >= n || to < 0 || to >= n){
            //
            return;
        }
        edge[from].push_back(to);
    }

    bool topological_sort(){
        vector<int> deg(n, 0);
        queue<int> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < edge[i].size(); j++){
                deg[edge[i][j]]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(deg[i] == 0)q.push(i);
        }

        res.clear();
        while(!q.empty()){
            int v = q.front(); q.pop();
            res.push_back(v);
            for(int i = 0; i < edge[v].size();i++){
                if(--deg[edge[v][i]] == 0){
                    q.push(edge[v][i]);
                }
            }
        }

        return res.size() == n;
    }
};
int main(void){
    int n, m, p[100000];
    TS ts;
    cin >> n >> m;
    ts.init(n);
    for(int i=0;i<n-1+m;i++){
        int a, b;
        cin >> a >> b;
        ts.add_edge(--a, --b);
    }
    ts.topological_sort();
    p[ts.res[0]] = 0;
    for(int i=0;i<n;i++){
        int v = ts.res[i];
        for(int j=0;j<ts.edge[v].size();j++){
            p[ts.edge[v][j]] = v+1;
        }
    }

    for(int i=0;i<n;i++){
        cout << p[i] << endl;
    }
}
