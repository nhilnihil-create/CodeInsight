#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
  double N, M, d; cin >> N >> M >> d;
  double ans;
  if(d) ans = 2*(N-d)/N/N*(M-1);
  else ans = 1/N*(M-1);
  cout << setprecision(10);
  cout << ans << endl;
  return 0;
}

