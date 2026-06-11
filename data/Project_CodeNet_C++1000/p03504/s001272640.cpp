#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

struct UnionFind {
    vector<int> par;
    vector<int> si;
    UnionFind(int N) : par(N), si(N) {
        for(int i = 0; i < N; ++i) par[i] = i;
        for(int i = 0; i < N; ++i) si[i] = 1;
    }

    int root(int x) {
        if(par[x] == x)return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
        si[ry] += si[rx];
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return si[root(x)];
    }
};
int N, C;
const int MAX_T = 1e5 + 1;



int main() {
    cin >> N >> C;
    vector<vector<int>>S(C, vector<int>(MAX_T, 0));
    int ans = 0;
    rep(i, N){
        int s, t, c;
        cin >> s >> t >> c;
        S[c - 1][s - 1] += 1;
        S[c - 1][t - 1] += -1;
    }

    rep(i, 1e5) {
        int tmp = 0;
        rep(j, C) {
            S[j][i + 1] += S[j][i];
            if(S[j][i + 1] == 1)S[j][i] = 1;
            tmp += S[j][i];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
