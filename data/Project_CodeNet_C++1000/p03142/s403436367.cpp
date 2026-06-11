#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N,M;cin >> N >> M;
    vector<vector<int>> G(N,vector<int>());
    vector<int> h(N);
    rep(i,N-1+M){
        int a,b;cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        h[b]++;
    }
    queue<int> zero;

    rep(i,N)if(h[i] == 0)zero.push(i);

    vector<int> dist(N);    //dist[i]:=i番目の頂点を通るときの最長経路      この問題では根っこが1つしかないはずなので、根っこからの最長距離にあたるはず
    
    int j = 0;
    while(zero.size()){
        int v = zero.front();zero.pop();
        for(auto nv : G[v]){
            h[nv]--;
            chmax(dist[nv],dist[v]+1);
            if(h[nv] == 0)zero.push(nv);
        }
    }

    vector<int> ans(N,-1);
    rep(v,N) for(auto nv : G[v]) if(dist[nv] - dist[v] == 1) ans[nv] = v;   // 距離の差が1のものが必然的に隣り合ったもので、これがもともとのグラフの経路のはず。※1

    rep(i,N)cout << ans[i] + 1 << endl;     // +1 はグラフ作成時に0indexにしたやつをもとに戻すのと、根っこは0を出力なので、-1+1=0にするため。根は一つしかないから（至言）

}

// ※1 これに関しては、解説放送がわかりやすい。
//     端的に説明すると、距離差が2以上のとき、つまり頂点をジャンプして子孫につながるルートが正規ルートだと仮定すると、距離差１の経路は新たに頂点を生まないと生えてこないことになる。
//     これは明らかにグラフ形成と有向辺の追加のルールに反しているので矛盾。
