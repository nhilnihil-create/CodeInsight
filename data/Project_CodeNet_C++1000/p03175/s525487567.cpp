#include <bits/stdc++.h>

using namespace std;
int n;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
vector<int> edges[MAXN];
pair<long long int, long long int> dp[MAXN];
pair<long long int, long long int> null = {-1, -1};

// ans.first - Black, ans.second - White
pair<int, int> dfs(int start = 1, int parent = 0){
    if(dp[start] != null){
        return dp[start];
    }else{
        pair<long long int, long long int> ans = {1, 1};
        for(int neigh : edges[start]){
            if(neigh != parent){
               auto temp_ans = dfs(neigh, start);
               // White
               ans.second = ans.second * (temp_ans.first + temp_ans.second) % MOD;
               
               // Black
               ans.first = (ans.first * temp_ans.second) % MOD; 
            }
        }
        dp[start] = ans;
        return ans;
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n - 1; ++i){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
        dp[i] = null;
    }
    dp[n - 1] = null;
    dp[n] = null;
    auto ans =  dfs();
    long long int final_ans = ans.first + ans.second;
    final_ans %= MOD;
    cout << final_ans << "\n";
    return 0;
}