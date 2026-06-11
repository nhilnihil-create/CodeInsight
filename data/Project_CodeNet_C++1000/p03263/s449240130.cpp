#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

int H, W;
vector<tuple<int, int, int, int>> ans(0);

void func(P p1, P p2){
  int a = p1.first, b = p1.second, c = p2.first, d = p2.second;
  int y = a, x = b;
  while(true){
    if(y % 2 == 0){
      if(x != W-1){
        ans.push_back(make_tuple(y, x, y, x+1));
        x++;
      }
      else{
        ans.push_back(make_tuple(y, x, y+1, x));
        y++;
      }
    }
    else{
      if(x != 0){
        ans.push_back(make_tuple(y, x, y, x-1));
        x--;
      }
      else{
        ans.push_back(make_tuple(y, x, y+1, x));
        y++;
      }
    }
    if(y == c && x == d) break;
  }
  
}

int main(){
  cin >> H >> W;
  vvi a(H, vi(W, 0));
  vector<P> odd(0);
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }
  for(int i = 0; i < H; i++){
    if(i % 2 == 0){
      for(int j = 0; j < W; j++){
        if(a.at(i).at(j) % 2 != 0) odd.push_back(P(i, j));
      }
    }
    else{
      for(int j = W-1; j >= 0; j--){
        if(a.at(i).at(j) % 2 != 0) odd.push_back(P(i, j));
      }
    }
  }

  
  int num = odd.size()/2;

  for(int i = 0; i < num; i++){
    int p = 2 * i, q = 2 * i + 1;
    func(odd.at(p), odd.at(q));
  }
  cout << ans.size() << endl;
  for(auto x: ans) cout << get<0>(x)+1 << ' ' << get<1>(x)+1 << ' ' << get<2>(x)+1 << ' ' << get<3>(x)+1 << endl;
}