#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;
    cin >> n >> m;
    
    vector<int> v[n+1];
    vector<int> degree(n+1, 0);
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }
    
    vector<int> temp;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0){
            q.push(i);
            temp.push_back(i);
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(auto x : v[cur]){
            degree[x]--;
            if(degree[x] == 0) {
                q.push(x);
                temp.push_back(x);
            }
        }
    }
    
    vector<int> dp(n+1, 0);
    
    for(auto cur : temp) {
        for(auto x : v[cur])
            dp[x] = max(dp[x], dp[cur] + 1);
    }
    
    int maxi = 0;
    for(int i = 1; i <= n; i++)
        maxi = max(maxi, dp[i]);
    
    cout << maxi ;
    return 0;
}