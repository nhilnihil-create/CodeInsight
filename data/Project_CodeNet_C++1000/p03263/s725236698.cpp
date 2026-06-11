#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589;

int main(){
  int H, W;
  cin >> H >> W;
  int a[500][500];
  rep(i, H){
    rep(j, W){
      cin >> a[i][j];
    }
  }
  vector<tuple<int, int, int, int>> move;
  rep(i, H-1){
    rep(j, W){
      if(a[i][j] % 2 == 1){
        tuple<int, int, int, int> tmp = make_tuple(i+1, j+1, i+2, j+1);
        move.push_back(tmp);
        a[i+1][j]++;
      }
    }
  }
  rep(i, W-1){
    if(a[H-1][i] % 2 == 1){
      tuple<int, int, int, int> tmp = make_tuple(H, i+1, H, i+2);
      move.push_back(tmp);
      a[H-1][i+1]++;
    }
  }
  cout << move.size() <<endl;
  for(tuple<int, int, int, int> x:move){
    printf("%d %d %d %d\n", get<0>(x), get<1>(x), get<2>(x), get<3>(x));
  }
}