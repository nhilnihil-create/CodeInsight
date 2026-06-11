#include<iostream>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int A[M] = {0};
  rep(i,0,N-1) {
    int K;
    cin >> K;
    rep(j,0,K-1) {
      int a;
      cin >> a;
      A[a-1]++;
    }
  }

  int ans = 0;
  rep(i,0,M-1) {
    if (A[i] == N) ans++;
  }
  cout << ans << endl;

  return 0;
}
