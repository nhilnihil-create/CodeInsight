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
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int res = INF;
int n, a, b, c;
vector<int> take;

void dfs(vector<vector<int>> list, int cnt, int cost){
    if(cnt == n){
        if(list[0].size()==0 || list[1].size()==0 || list[2].size()== 0) return;
        int len[3] = {0, 0, 0};
        rep(i, 3){
            rep(j, list[i].size()){
                len[i] += take[list[i][j]];
            }
        }
        int sum = abs(len[0]-a)+abs(len[1]-b)+abs(len[2]-c);
        chmin(res, sum + cost);

    }else{
        dfs(list, cnt + 1, cost);
        rep(i, 3){
            list[i].push_back(cnt);
            dfs(list, cnt + 1, cost + 10);
            list[i].pop_back();
        }
    }
}

int main() {
    cin >> n >> a >> b >> c;
    take.resize(n);
    rep(i, n) cin >> take[i];
    vector<vector<int>> list(3, vector<int>());

    dfs(list, 0, -30);
    
    cout << res << ln;
}