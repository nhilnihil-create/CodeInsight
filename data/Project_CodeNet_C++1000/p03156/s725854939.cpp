#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N, A, B;
  cin >> N >> A >> B;

  int a = 0, b = 0, c = 0;
  rep(i, N) {
    int p; cin >> p;
    if (p <= A)
      ++a;
    else if (p <= B)
      ++b;
    else
      ++c;
  }
  cout << min(a, min(b, c)) << "\n";

  return 0;
}
