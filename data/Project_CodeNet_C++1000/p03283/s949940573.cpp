#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N, M, Q;
  // 入力: H × W のグリッド
  cin >> N >> M >> Q;
  int H, W; 
  H = N;
  W = N;
  vector<vector<ll> > a(H, vector<ll>(W,0));

  while(M--){
    int tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--;
    tmp2--;
    a[tmp1][tmp2]++;
  }

  // 二次元累積和
  vector<vector<ll> > s(H+1, vector<ll>(W+1, 0));
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

  // クエリ [x1, x2) × [y1, y2) の長方形区域の和
  while(Q--){
    int x1, x2, y1, y2;
    cin >> x1 >> x2;
    x1--;
    y1 = x1;
    y2 = x2; 
    
    cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
  }
}
