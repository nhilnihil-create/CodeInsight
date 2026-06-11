#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, ans{200000};
  string S;
  cin >> N >> S;
  vector<int> l(N+1), r(N+1);
  for (int i = 0; i != N; ++i) {
    l[i+1] = l[i] + (S[i] == '#');
    r[N-i-1] = r[N-i] + (S[N-i-1] == '.');
  }
  for (int i = 0; i <= N; ++i) ans = min(ans, l[i] + r[i]);
  cout << ans << endl;
}

