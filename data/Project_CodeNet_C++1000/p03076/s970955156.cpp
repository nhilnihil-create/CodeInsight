#include<iostream>
#include<utility>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int f(int n) {
  return n % 10;
}

int main() {
  int A[5];
  rep(i,0,4) cin >> A[i];

  pair<int, int> last = make_pair(-1, 9);
  rep(i,0,4) {
    if (f(A[i]) == 0) continue;
    if (f(A[i]) < last.second) {
      last = make_pair(i, f(A[i]));
    }
  }

  if (0 <= last.first) swap(A[last.first], A[4]);
  rep(i,0,3) {
    while (f(A[i]) != 0) A[i]++;
  }

  int ans = 0;
  rep(i,0,4) ans += A[i];
  cout << ans << endl;

  return 0;
}
