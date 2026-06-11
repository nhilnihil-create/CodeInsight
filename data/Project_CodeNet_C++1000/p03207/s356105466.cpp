#include <iostream>
using namespace std;

int main() {
  int N, max = 0, ans = 0; cin >> N;
  for(int i = 0; i < N; i++) {
    int p; cin >> p;
    ans += p;
    if(max < p) max = p;
  }
  cout << ans - max / 2 << endl;
  return 0;
}