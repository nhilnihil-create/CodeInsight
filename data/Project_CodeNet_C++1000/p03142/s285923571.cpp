#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(100000);
vector<bool> done(100000);
void dfs(int v, vector<int> &t) {
    if (done.at(v)) return;

    done.at(v) = true;
    for (int to: graph.at(v)) {
        dfs(to, t);
    }
    t.push_back(v);
} 
void topological_sort(int n, vector<int> &t) {
    for (int i = 0; i < n; i++) {
        dfs(i, t);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rgraph(n);
    for (int i = 0; i < n - 1 + m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph.at(a).push_back(b);
        rgraph.at(b).push_back(a);
    }

    vector<int> t;
    topological_sort(n, t);

    vector<int> new_num(n);
    for (int i = n - 1; i >= 0; i--) {
        new_num.at(t.at(i)) = n - i;
    }
    
    for (int i = 0; i < n; i++) {
        int max_num = -1;
        int par = -1;
        for (int p: rgraph.at(i)) {
            if (max_num < new_num.at(p)) {
                par = p;
                max_num = new_num.at(p);
            }
        }
        cout << par + 1 << endl;
    }
}