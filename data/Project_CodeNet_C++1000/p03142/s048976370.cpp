//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d

//参考：
//https://scrapbox.io/ganariya/AtCoder%E5%85%A8%E5%9B%BD%E7%B5%B1%E4%B8%80%E3%83%97%E3%83%AD%E3%82%B0%E3%83%A9%E3%83%9F%E3%83%B3%E3%82%B0%E7%8E%8B%E6%B1%BA%E5%AE%9A%E6%88%A6%E4%BA%88%E9%81%B8_D%E5%95%8F%E9%A1%8C500%E7%82%B9_%E3%80%8CRestore_the_Tree%E3%80%8D

//ポイント：トポロジカルソート（詳細はコード内で説明）

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;
vector<vector<LL>> out;
vector<vector<LL>> in;

vector<LL> ans;

void solve(){
    //トポロジカルソート
    //有向グラフで、かつ閉路がない場合に使える（このようなグラフをDEGという）
    //頂点i->jという辺がある時、dist[i]<dist[j]が成り立つように数列distを組む
    //このようなdistをトポロジカル順序という（点startから点iへの距離的なもの）

    //ある頂点iに入っていく辺の個数をin_num[i]とおく
    //ついでにトポロジカルソートのスタート地点にしたい点を求める
    //入っていく辺のない頂点がスタート地点となる点である
    vector<LL> in_num(N+1,0);
    LL start;//トポロジカルソートのスタート地点にしたい点
    for(int i=1;i<=N;i++){
        in_num[i] = in[i].size();
        if(in_num[i]==0) start = i;
    }

    //BFSを使ってトポロジカル順序(点startから点iへの距離的なもの)を求める
    queue<LL> q;
    //dist,parentにはトポロジカルソートの結果を格納
    vector<LL> dist(N+1,0);//点startから点iへの距離的なもの
    vector<LL> parent(N+1,0);//点iの直接の親をparent[i]とする
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        LL now = q.front();q.pop();
        for(LL next:out[now]){
            if(dist[next]<dist[now]+1){//距離がでかい方優先
                dist[next] = dist[now]+1;
                parent[next] = now;//親を更新
                in_num[next]--;
                if(in_num[next]==0) q.push(next);
            }
        }
    }

    ans = vector<LL>(N+1,0);
    for(int i=1;i<=N;i++){
        ans[i] = parent[i];
    }
}

int main(){
    cin >> N >> M;
    out = vector<vector<LL>>(N+1);
    in = vector<vector<LL>>(N+1);
    for(int i=0;i<N+M-1;i++){
    	LL u,v;cin >> u >> v;
    	out[u].push_back(v);
        in[v].push_back(u);
    }

    solve();

    for(int i=1;i<=N;i++)cout << ans[i] << endl;
    return 0;
}