#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    vector<int> num(n, 0);
    int a, b;
    for (int i = 0; i < n + m - 1; i++){
        cin >> a >> b;
        a--; b--;
        num[b]++;
        edge[a].push_back(b);
    }
    vector<int> ans(n);
    vector<int> d(n, 0);
    int root;
    for (int i = 0; i < n; i++) if (num[i] == 0) root = i;
    ans[root] = 0;
    queue<int> q;
    q.push(root);
    while (q.size()){
        root = q.front(); q.pop();
        for (int i = 0; i < edge[root].size(); i++){
            num[edge[root][i]]--;
            if (num[edge[root][i]] == 0) {
                ans[edge[root][i]] = root + 1;
                q.push(edge[root][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}