#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int sum = 0;
  int mx = 0;
  for (int n = 0; n < N; ++n) {
    int P;
    cin >> P;
    sum += P;
    mx = max(mx, P);
  }
  sum -= mx / 2;
  cout << sum << endl;
  
  return 0;
}
