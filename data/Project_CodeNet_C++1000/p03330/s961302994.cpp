#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int N, C; cin >> N >> C;
    vector<vector<int>> d(C, vector<int>(C)), c(N, vector<int>(N));
    rep(i,C) rep(j,C) cin >> d[i][j];
    rep(i,N) rep(j,N) cin >> c[i][j], c[i][j]--;
    
    // s[i][j] : iグループを色jにするときの違和感
    vector<vector<int>> s(3, vector<int>(C));
    rep(i,N) rep(j,N) {
        int w = (i+j)%3;
        rep(k,C) {
            s[w][k] += d[c[i][j]][k];
        }
    }

    int ans = 250000010;
    rep(i,C) rep(j,C) rep(k,C) {
        if (i == j || j == k || k == i) continue;
        chmin(ans, s[0][i]+s[1][j]+s[2][k]);
    }
    cout << ans << endl;
    return 0;
}
