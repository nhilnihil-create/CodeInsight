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
    ll count;
};

ll H, W;
ll y, x, count;  // キューから取り出した座標と操作回数
vector<string> vec;  // 座標を受け取る配列
queue<Corr> q;   //構造体Corr型を格納するキューの生成

vector<ll> dy = {0, 0, -1, +1};
vector<ll> dx = {-1, +1, 0, 0};

ll bfs() {
  while ( !q.empty() )  {
    Corr now = q.front(); q.pop();   //キューの先頭を取り出す
    y = now.y, x = now.x, count = now.count;
    
    //上下左右4方向を探索、マス目内かつ白いマス目の場合、キューに追加
    for ( ll i = 0; i < 4; ++i) {
      Corr next = {y + dy[i], x + dx[i], count + 1};
      if (0 <= next.y && next.y <= H-1 && 0 <= next.x && next.x <= W-1 && vec[next.y][next.x] == '.') {
                vec[next.y][next.x] = '#';  // 同じ場所を探索しないようにする
                q.push(next);
            }
    }
  }
  return count;
}

int main() {
  cin >> H >> W;
  vec.resize(H); for ( ll i = 0; i < H; ++i ) cin >> vec[i];
  
  for ( ll y = 0; y < H; y++ ) {
    for ( ll x = 0; x < W; x++ ) {
      if( vec[y][x] == '#' ) {
        Corr start = {y, x, 0};   //スタート位置(黒いマス目)をキューに追加
        q.emplace(start);
      }
    }
  }
  
  cout << bfs() << endl;
  
  return 0; 
}