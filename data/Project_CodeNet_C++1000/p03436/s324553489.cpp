#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64_t)1e18
#define INF (int32_t)1e9

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

int H, W;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
  cin >> H >> W;
  int white = 0;

  vector<string> s(H);
  for (auto&& e : s) {
    cin >> e;
    for (auto &&c : e) {
      if (c == '.') white++;
    }
  }

  auto dis = make_v<int>(H, W);
  fill_v<int>(dis, INF);
  dis[0][0] = 0;

  using T = tuple<int, int, int>;
  queue<T> que;
  que.emplace(0, 0, 0);

  auto valid = [&](int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W && s[y][x] != '#';
  };

  while (que.size()) {
    int d, y, x;
    tie(d, y, x) = que.front(); que.pop();

    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k], nx = x + dx[k];
      if (!valid(ny, nx)) continue;
      if (dis[ny][nx] <= d + 1) continue;

      dis[ny][nx] = d + 1;
      que.emplace(d+1, ny, nx);
    }
  }

  if (dis[H-1][W-1] == INF) {
    cout << -1 << endl;
  } else {
    cout << white - dis[H-1][W-1] - 1 << endl;
  }
}
