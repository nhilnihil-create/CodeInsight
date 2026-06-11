#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  //input
  int N, M;
  cin >> N >> M;
  vector <int> cnt(M);
  /*
  vector< vector<int> > A (30, vector<int>(30) );
  rep(i,N){
    cin >> K[i];
    rep(j,K[i]){
      cin >> A[i][j];
    }
  }
  */
  rep(i,N){
    int K;
    cin >> K;
    rep(j,K){
      int  A;
      cin >> A;
      A--;
      cnt[A] ++;
    }
  }

  //solve
  int ans = 0;
  rep(i,M){
    if (cnt[i] ==  N) ans ++;
  }

  //output
  cout << ans << endl;
}
