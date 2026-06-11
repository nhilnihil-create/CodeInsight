#include "bits/stdc++.h"
#define REP(i, m, n) for(long long i = m; i < n; ++i)
#define CO(n) cout << n << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//二部グラフであれば，二部グラフを保ったまま辺の数を最大化
//B*(N-B)-M
//そうでなければ全ての頂点を結ぶ
//N*(N-1)/2

//V頂点数，E辺数
ll N, M;
//辺
vector<int> G[100000];
//二部グラフ用
int color[100000];
//1の個数
int B=0;

//二部グラフ判定
bool dfs(int v, int c) {
    color[v] = c;
    if (c == 1) ++B;
    REP(i,0,G[v].size()){
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i,0,M){
        int from, to;
        cin >> from >> to;
        --from; --to; //0〜N-1にする
        G[from].push_back(to);
        G[to].push_back(from);
    }
    if (dfs(0,1)) {
        // CO("yes");
        CO(B*(N-B)-M);
    } else {
        // CO("no");
        CO(N*(N-1)/2 - M);
    }
    // REP(i,0,N) cout << color[i] << ' ';
    // cout << endl;
    return 0;
}
