#include <bits/stdc++.h>

using namespace std;
vector<int> g[200001];
int mx  = 0 , vert = 1;
void dfs(int cur , int len = 0, int p = -1) {
    if(len > mx) {
        mx = len;
        vert = cur;
    }
    for(auto to : g[cur]) {
        if(to != p)
            dfs(to , len + 1 , cur);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a , b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    mx = 0;
    dfs(vert);
    if(mx % 3 == 1)
        cout << "Second";
    else
        cout << "First";
    return 0;
}
