#include<iostream>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int A, ans = X;
  rep(i,0,N-1) {
    cin >> A;
    ans += (D + A - 1) / A;
  }
  cout << ans << endl;
  return 0;
}
