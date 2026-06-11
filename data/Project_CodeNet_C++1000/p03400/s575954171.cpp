#include <iostream>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)

int main() {
  int N,D,X;
  cin >> N >> D >> X;

  int ans{X};
  int a;
  for (int i = 0; i != N; ++i) {
    cin >> a;
    ans += (D-1)/a+1;
  }

  cout << ans << endl;
  
  return 0;
}
