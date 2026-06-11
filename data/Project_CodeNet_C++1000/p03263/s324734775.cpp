#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> coins(H+2, vector<int>(W+2, -1));
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> coins[i][j];
        }
    }
    int cnt = 0;
    vector<vector<int>> res;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(coins[i][j]%2 == 0) continue;
            bool r = false, d = false;
            if(coins[i+1][j] != -1 && coins[i+1][j]%2 == 1) d = true;
            if(coins[i][j+1] != -1 && coins[i][j+1]%2 == 1) r = true;            

            if(d){
                cnt++;
                coins[i+1][j]++; coins[i][j]--;
                res.push_back({i, j, i+1, j});
            }else if(r){
                cnt++;
                coins[i][j+1]++; coins[i][j]--;
                res.push_back({i, j, i, j+1});             
            }else if(coins[i+1][j] != -1){
                cnt++;
                coins[i+1][j]++; coins[i][j]--;
                res.push_back({i, j, i+1, j});                
            }else if(coins[i][j+1] != -1){
                cnt++;
                coins[i][j+1]++; coins[i][j]--;
                res.push_back({i, j, i, j+1});                     
            }
        }
    }
    cout << cnt << ln;
    for(vector<int> v: res){
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << ln;
    }    
}