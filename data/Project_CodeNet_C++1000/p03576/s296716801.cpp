#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

long long MOD = 1000000000 + 7;
long long MAX = LLONG_MAX;

int main(){
  cout << setprecision(10);
  int N,K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  vector<pll> v(N);

  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i];

    v.at(i) = make_pair(A[i],B[i]);
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

    // 入力: H × W のグリッド
  int H, W; 
  H = N; W = N;
  vector<vector<int> > a(H, vector<int>(W, 0));

  for(int i = 0; i < N; i++){
    ll x = v[i].first;
    ll y = v[i].second;

    int x_index = lower_bound(A.begin(), A.end(), x) - A.begin();
    int y_index = lower_bound(B.begin(), B.end(), y) - B.begin();

    a[x_index][y_index]++;

  }

  // 二次元累積和
  vector<vector<int> > s(H+1, vector<int>(W+1, 0));
  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];
    }
  }

  ll ans = MAX;
  for(int x1 = 0; x1 < N; x1++){
    for(int x2 = x1+1; x2 <= N; x2++){
      for(int y1 = 0; y1 < N; y1++){
        for(int y2 = y1+1; y2 <= N; y2++){
          int num = s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
          if(num >= K){
            ll area = ( A[x2-1] - A[x1] ) * (B[y2-1] - B[y1]);
            ans = min(ans, area);
          }
        }
      }
    }
  }

  cout << ans << endl;
}
