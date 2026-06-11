#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, M; cin >> N >> M;

  vector<int> Shurui( M, 0 );
  rep( i, 0, N ) {
    int K; cin >> K;
    rep( j, 0, K ) {
      int A; cin >> A;
      Shurui.at(A-1)++;
    }
  }

  int Ans = 0;
  rep( i, 0, M ) {
    if ( Shurui.at(i) == N ) Ans++;
  }

  cout << Ans << endl;
}
