#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long add(long long a, long long b) {
    long long res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

long long sub(long long a, long long b) {
    long long res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

long long mul(long long a, long long b) {
    return (((a % mod) * (b % mod)) % mod);
}

long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }
    if(x > y){
         return gcd(y, x % y);
    }
    else{
         return gcd(x, y % x);
    }
}

void dfs(vector<vector<int>> &v, vector<int> &visited, int node, int &ans){
    if(visited[node]){
        return;
    }
    visited[node] = 1;
    ans++;
    for(auto i : v[node]){
        dfs(v, visited, i, ans);
    }
}

/*bool good(vector<int> &v, int d, int mid){
    vector<int> p(v.size());
    p[0] = v[0] - mid;
    for(int i = 1;i < v.size();i++){
        p[i] = p[i - 1] + (v[i] - mid);
    }
    vector<int> m(v.size());
    m[0] = p[0];
    int mi = m[0];
    for(int i = 1;i < v.size();i++){
        mi = min(mi, p[i]);
        m[i] = mi;
    }
    for(int r = 0;r < v.size();r++){
        if(r - d > 0){
            if(m[r - d - 1] <= p[r]){
                L = r - d;
                R = r;
                return true;
            }
        }
    }
    return false;
}*/

bool comp(pair<int, int> x, pair<int, int> y){
    if(x.first < y.first)return true;
    else if(x.first == y.first){
        if(x.second < y.second)return true;
        else return false;
    }
    else{
        return false;
    }
}

char grid[1002][1002];
int dp[1002][1002];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> grid[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(grid[i - 1][j] == '.'){
                dp[i][j] += (dp[i - 1][j] % mod);
            }
            if(grid[i][j - 1] == '.'){
                dp[i][j] += (dp[i][j - 1] % mod);
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][m] % mod << endl;
 }
/*
5 2
-1 -2 -3 4 5
2 3
4

-3 -2 -1 4 5
2 3
5 + (-3) = 2
4 + -2 = 2
ans = 4

-3 -2 -1 4 5
3 2
5 + -3 = 2
4 + -1 = 3
ans = 5
*/
