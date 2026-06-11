#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int INF = 100000;
const int MAX_N = 1005;


const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int h,w;
string c[MAX_N];


int main(){
    cin >> h >> w;
    rep(i,h){
        cin >> c[i];
    }

    queue<P> que;
    vector<vector<int> > dist(h,vector<int>(w,-1));
    rep(i,h){
        rep(j,w){
            if(c[i][j] == '#'){
                que.push(make_pair(i,j));
                dist[i][j] = 0;
            }
        }
    }

    while(!que.empty()){
        P current_pos = que.front();
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop();

        rep(dir,4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || h<=nx || ny<0 || w<=ny) continue;
            if(dist[nx][ny]== -1){
                dist[nx][ny] = dist[x][y]+1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    int ans =0;
    
    rep(i,h){
        rep(j,w){
            ans = max(ans,dist[i][j]);
        }
    }

    cout << ans <<endl;

}