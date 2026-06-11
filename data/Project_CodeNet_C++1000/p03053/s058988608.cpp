#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int mod = 1000000007;
//const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> ar(h, vector<char>(w));
    rep(i,h) rep(j,w) cin >> ar[i][j];
    vector<vector<int>> co(h,vector<int>(w,INF));
    vector<P> k;
    rep(i,h) rep(j,w) if (ar[i][j] == '#'){
        k.emplace_back(P(i,j));
        co[i][j] = 0;
    }
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    queue<P> qq;
    rep(i,k.size()) qq.push(k[i]);
    while (!qq.empty()){
        P pq = qq.front(); qq.pop();
        int x = pq.first;
        int y = pq.second;
        int c = co[x][y] + 1;
        rep(j,4){
            if (range(0,h,x+dx[j])&&range(0,w,y+dy[j])&&co[x+dx[j]][y+dy[j]]==INF){
                co[x+dx[j]][y+dy[j]] = c;
                qq.push(P(x+dx[j],y+dy[j]));
            }
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) ans = max(ans,co[i][j]);
    cout << ans << endl;
}