#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1][b-1] = 1;
        adj[b-1][a-1] = 1;
    }
    vector<int> check(n, 0);
    queue<int> q;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(adj[i][j] == 0) continue;
            adj[i][j] = 0;
            adj[j][i] = 0;
            q.push(0);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                if(check[node] == 1) continue;
                check[node] = 1;
                for(int k = 0; k < n; k++){
                    if(adj[node][k] == 1) q.push(k);
                }
            }
            int sum = 0;
            for(int k = 0; k < n; k++){
                sum += check[k];
                check[k] = 0;
            }
            if(sum < n) ans++;
            adj[i][j] = 1;
            adj[j][i] = 1;
        }
    }
    cout << ans << endl;
}