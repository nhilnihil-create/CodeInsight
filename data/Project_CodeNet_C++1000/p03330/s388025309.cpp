#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, C;
int D[50][50], c[1000][1000];

signed main(){
    cin >> N >> C;
    REP(i, C) REP(j, C) cin >> D[i][j];
    REP(i, N) REP(j, N) {cin >> c[i][j]; c[i][j]--;}
    map<int, int> mp[3];
    REP(i, N) REP(j, N) mp[(i + j) % 3][c[i][j]]++;
    int ans = INT32_MAX;
    REP(i, C){
        REP(j, C){
            REP(k, C){
                if(i == j || j == k || k == i) continue;
                int cost = 0;
                for(auto p : mp[0]) cost += D[p.first][i] * p.second;
                for(auto p : mp[1]) cost += D[p.first][j] * p.second;
                for(auto p : mp[2]) cost += D[p.first][k] * p.second;
                ans = min(ans, cost);
            }
        }
    }
    PRINT(ans);
    return 0;
}