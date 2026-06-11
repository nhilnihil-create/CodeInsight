#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int n, a, b, c;
vector<int> l;

int dfs(int i, int A, int B, int C, int None, int cost){
    int ret = INF;
    if(i == n){
        ret = cost;
        ret += abs(A - a) + abs(B - b) + abs(C - c);
        if(A == 0 || B == 0 || C == 0) ret = INF;
        return ret;
    }
    chmin(ret, dfs(i+1, A+l[i], B, C, None, cost+(A==0 ? 0 : 10)));
    chmin(ret, dfs(i+1, A, B+l[i], C, None, cost+(B==0 ? 0 : 10)));
    chmin(ret, dfs(i+1, A, B, C+l[i], None, cost+(C==0 ? 0 : 10)));
    chmin(ret, dfs(i+1, A, B, C, None+l[i], cost));
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> c;
    l.resize(n);
    rep(i,n) cin >> l[i];
    int ans = dfs(0, 0, 0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}