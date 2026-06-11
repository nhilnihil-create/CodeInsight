#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr int NA {10000};

int main() {
  int N,T;
  cin >> N >> T;

  int c,t;
  int ans{NA};
  for (int i = 0; i < N; i++) {
    cin >> c >> t;
    if (t <= T) {
      ans = min(ans,c);
    }
  }

  cout << (ans == NA ? "TLE" : to_string(ans)) << endl;
  return 0;
}
