#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C, 0));
    rep(i,C) rep(j,C) cin >> D[i][j];
    vector<vector<int>> c(N, vector<int>(N, 0));
    rep(i,N) rep(j,N) {
        cin >> c[i][j];
        c[i][j]--;
    }

    vector<vector<int>> cost(C, vector<int>(3, 0));
    
    rep(k,C) {
        rep(i,N) rep(j,N) cost[k][(i + j) % 3] += D[c[i][j]][k];
    }

    int minimum = INF;
    rep(i,C) rep(j,C) rep(k,C) {
        if (i != j && j != k && k != i) {
            minimum = min(minimum, cost[i][0] + cost[j][1] + cost[k][2]);
        }
    }

    cout << minimum << endl;
    
    return 0;
}