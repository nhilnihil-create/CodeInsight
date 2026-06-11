/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define repr4(i,s,n) for(ll i = (n);i>=(s);i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;
/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/
const int mod = 1000000007;



int main(){
int H,W;
cin>>H>>W;
char G[H][W];
rep(i,H)rep(j,W)cin>>G[i][j];
// BFS のためのデータ構造
    vector<vector<int>> dist(H,vector<int>(W,-1)); // 全頂点を「未訪問」に初期化
    queue<int> que_y,que_x;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

rep(i,H)rep(j,W){
    if(G[i][j]=='.')continue;
    // 初期条件 (頂点 (sx,sy) を初期ノードとする)
    dist[i][j] = 0;
    que_y.push(i);
    que_x.push(j);
} 
    //移動方法4通り
    

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que_x.empty()) {
        int y = que_y.front(); // キューから先頭頂点を取り出す
        que_y.pop();
        int x = que_x.front();
        que_x.pop();

        // (x,y) から辿れる頂点をすべて調べる
       rep(i,4) {
            if ((y+dy[i]>=0)&&(y+dy[i]<H)&&(x+dx[i]>=0)&&(x+dx[i]<W)&&(G[y+dy[i]][x+dx[i]]=='.')){ //道でなければ飛ばす
            if(dist[y+dy[i]][x+dx[i]] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな頂点について距離情報を更新してキューに追加する
            dist[y+dy[i]][x+dx[i]] = dist[y][x] + 1;
            que_y.push(y+dy[i]);
            que_x.push(x+dx[i]);
            }
        }
    }
    int ans=0;
    rep(i,H)rep(j,W)ans=max(ans,dist[i][j]);
    cout<<ans<<endl;

return 0;
}