#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;   //long型よりも使用できる桁数が増える

// 座標 corrdinate とゴールまでのマス目の数を保持するための構造体
struct Corr {
    ll y;
    ll x;
    ll sum;
};

ll H, W;
ll sy, sx, gy, gx;
ll y, x, sum;  // キューから取り出した座標
vector<string> vec;  // 座標を受け取る配列
queue<Corr> q;   //構造体Corr型を格納するキューの生成

vector<ll> dy = {0, 0, -1, +1};  // 進む方向の簡便化，テクニックとして覚えておく．
vector<ll> dx = {-1, +1, 0, 0};  // ループで回すことで上下左右に移動できるようになっている

ll bfs() {
  while ( !q.empty() )  {
    Corr now = q.front(); q.pop();   //キューの先頭を取り出す
    y = now.y, x = now.x, sum = now.sum;
    
    if (y == gy && x == gx) return sum;   //現在の座標がゴールの場合深さを返却
    
    //上下左右4方向を探索、#ではないかつまだ訪れていない場合キューに追加
    for ( ll i = 0; i < 4; ++i) {
      Corr next = {y + dy[i], x + dx[i], sum + 1};
      if (0 <= next.y && next.y <= H-1 && 0 <= next.x && next.x <= W-1 && vec[next.y][next.x] == '.') {
                vec[next.y][next.x] = '#';  // 同じ場所を探索しないようにする
                q.push(next);
            }
    }
  }
  return -1;
}

int main() {
  cin >> H >> W;
  sy = 0, sx = 0, gy = H - 1, gx = W - 1;
  vec.resize(H); for ( ll i = 0; i < H; ++i ) cin >> vec[i];
  
  int count_all = 0; 
  int count_w = 0;
  int count_b = 0;
  count_all = (H)*(W);           //全体のマス目の数
  for ( ll y = 0; y < H; y++ ) {
    for ( ll x = 0; x < W; x++ ) {
      if( vec[y][x] == '#' ) {
        count_b++;                   //黒いマス目の数
      }
    }
  }
  
  Corr start = {sy, sx, 1};
  q.emplace(start);   //初期位置をキューに格納
  
  int count_x = count_all - count_b;
  
  count_w = bfs();    //スタートからゴールまでのマス目の数
  if ( count_w == -1 ) {
    cout << -1 << endl;
  } else {
    cout << count_x - count_w << endl;
  }
  
  return 0; 
}