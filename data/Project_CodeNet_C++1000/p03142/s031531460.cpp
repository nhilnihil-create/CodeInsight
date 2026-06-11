#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n, m, u, v;
    cin >> n >> m;
    unordered_map<int, vector<int>> out_deg;
    unordered_map<int, int> in_deg;
    vector<int> ans(n+1, 0);
    for(int i = 0; i < n-1+m; i++) {
        cin >> u >> v;
        in_deg[v] += 1;
        out_deg[u].push_back(v);
    }
    vector<int> dq;
    for(int i = 1; i <= n; i++) {
        if (in_deg[i] == 0)
            dq.push_back(i);
    }
    while(!dq.empty()) {
        vector<int> new_dq;
        for(int node: dq) {
            for(int neibor: out_deg[node]) {
                if (--in_deg[neibor] == 0) {
                    ans[neibor] = node;
                    new_dq.push_back(neibor);
                }
            }
        }
        dq.swap(new_dq);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}


