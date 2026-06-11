#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, c; cin >> n >> c;
    vector<vector<int>>D(c, vector<int>(c, 0));
    rep(i,c)rep(j,c) cin >> D[i][j];
    vector<vector<int>>C(n, vector<int>(n, 0));
    rep(i,n)rep(j,n) cin >> C[i][j], --C[i][j];
    vector<vector<int>> cost(3, vector<int>(c, 0));
    for(int k = 0; k < c; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cost[(i+j)%3][k] += D[C[i][j]][k];
            }
        }
    }
    int ans = 1 << 30;
    for(int i = 0; i < c; ++i){
        for(int j = 0; j < c; ++j){
            if(i == j) continue;
            for(int k = 0; k < c; ++k){
                if(i == k || j == k) continue;
                int tmp = cost[0][i] + cost[1][j] + cost[2][k];
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}