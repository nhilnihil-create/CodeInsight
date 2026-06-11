#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#define lint long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++) // for簡略表記
#define DUMP(ar) for(int loop_dump=0; loop_dump<(int)ar.size(); loop_dump++) cout << "[" << loop_dump << "]:" << ar[loop_dump] << endl // 配列一覧表示
#define DUMPL(ar) for(int loop_dump=0; loop_dump<(int)ar.size(); loop_dump++) { cout << ar[loop_dump]; if(loop_dump<(int)ar.size()-1) cout << ' '; } cout << endl; // 配列一行一覧表示
#define COUT(x) cout << x << endl // 単要素出力
#define ALL(ar) ar.begin(), ar.end() // コンテナの全要素
#define LOOPD(i) cout << "ループ[" << i << "]回目---------------" << endl // ループ回数デバグ
using namespace std;
// cout << fixed << setprecision(4) で小数点以下4桁の桁そろえ
// cout << setw(5) << ... で表示形式を5桁に設定 5桁未満なら頭に空白がつく 5桁越なら先頭から5桁まで
// cout << setw(5) << setfill('0') << ... で空白部分の埋め文字に5を使う
// getline(cin, [変数]); で空白などを含む入力の受け取り(行ごとの受け取り)
// cin >> ws; でそこまでにストリームに残されたホワイトスペースを取り除く(=以降のgetlineの有効化)

struct union_find{
    vector<int> par;
    vector<int> size;
    union_find(int n){
        par.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    // yをxへ
    void unite(int x, int y){
        // cout << "x: " << x << "とy: " << y << "を接続" << endl;
        int par_x = find(x), par_y = find(y);
        if(size[par_x] > size[par_y]){
            size[par_x] += size[par_y];
            par[par_y] = find(x);
        }else{
            size[par_y] += size[par_x];
            par[par_x] = find(y);
        }

        // par[find(y)] = x;
        // cout << y << ":[" << par[y] << "]" << endl;
    }

    int find(int x){
        int tmp = x;
        while(par[tmp] != tmp){
            // cout << "x:" << x << " par[x]:" << par[x] << endl;
            tmp = par[tmp];
        }
        par[x] = tmp;
        return tmp;
    }

    bool same(int x, int y){
        return (find(x) == find(y));
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    FOR(i, n) cin >> p[i];
    vector<pair<int, int>> c(m);
    FOR(i, m) cin >> c[i].first >> c[i].second;

    union_find uf(n);
    for(int i=0; i<m; i++){
        uf.unite(c[i].first-1, c[i].second-1);
    }

    // DUMP(uf.par);

    int ans = 0;
    for(int i=0; i<n; i++){
        if(uf.same(i, p[i]-1)){
            ans++;
        }
    }

    COUT(ans);
    // DUMP(uf.par);

    return 0;
}