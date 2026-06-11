// 解き直し.
// ARC 102解説.
// https://img.atcoder.jp/arc102/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define p1 first
#define p2 second
const int MAX_N = 21;
typedef pair<int, int> pii;

vector<vector<pii>> graph(MAX_N);
int pow2[MAX_N];

int main(){
    
    // 1. 入力情報取得.
    int L;
    scanf("%d", &L);
    
    // 2. 解説通り.
    // 2-1. 頂点 i から 頂点 i + 1 へ, 長さ 0, pow2[i - 1] の 辺を, 1本ずつ張る.
    int r = 0, M = 0;
    pow2[0] = 1;
    for(int i = 1; i < MAX_N; i++){
        pow2[i] = pow2[i - 1] * 2;
        if(pow2[i] <= L) r++;
    }
    int N = r + 1;
    for(int i = 1; i < N; i++){
        graph[i].pb({i + 1, 0});
        graph[i].pb({i + 1, pow2[i - 1]});
        M += 2;
    }
    
    // 2-2. 条件を確認しながら, 頂点 t から 頂点 N に, 長さ L - pow2[t - 1] の 辺を, 1本ずつ張る.
    for(int t = N - 1; t >= 1; t--){
        if(L - pow2[t - 1] >= pow2[r]){
            graph[t].pb({N, L - pow2[t - 1]});
            L -= pow2[t - 1];
            M++;
        }
    }
    
    // 3. 出力.
    printf("%d %d\n", N, M);
    for(int i = 1; i <= N; i++){
        for(auto &o : graph[i]) printf("%d %d %d\n", i, o.p1, o.p2);
    }
    return 0;
}