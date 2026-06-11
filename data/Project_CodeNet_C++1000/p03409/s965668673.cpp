#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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
const int INT_INF = 1LL << 30;

//解説AC。最も効率的なマッチング方法が思い付かず。
//二部グラフの最大マッチング問題を勉強する。

struct xy{
  int x, y;
  xy(){}
  xy(int a, int b){x = a; y = b;}
};

bool xmin(xy a, xy b){
  return a.x < b.x;
}
bool ymax(xy a, xy b){
  return a.y > b.y;
}

int main(){
  int N;
  cin >> N;
  vector<xy> r(N), b(N);
  for(int i = 0; i < N; i++){
    cin >> r.at(i).x >> r.at(i).y;
  }
  sort(ALL(r), ymax);

  vvi BR(N, vi(0)); //i番目の青とペアになれる赤の番号
  for(int i = 0; i < N; i++){
    cin >> b.at(i).x >> b.at(i).y;
  }
  sort(ALL(b), xmin);

  for(int i = 0; i < N; i++){//青
    for(int j = 0; j < N; j++){//赤
      if(r.at(j).x < b.at(i).x && r.at(j).y < b.at(i).y){
        BR.at(i).push_back(j);
      }
    }
  }

  int ans = 0;
  vector<bool> rflag(N, true); //赤がペア作成済みか。
  for(int i = 0; i < N; i++){
    for(int j = 0; j < BR.at(i).size(); j++){
      if(rflag.at(BR.at(i).at(j))){
        rflag.at(BR.at(i).at(j))= false;
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}