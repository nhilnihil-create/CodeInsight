#include <iostream>
#include <set>

using namespace std;

int main() {
  int N, ans{};
  string A, B, C;
  cin >> N >> A >> B >> C;
  set<char> s;
  for (auto i = 0; i != N; ++i) {
    s.clear();
    s.insert({A[i],B[i],C[i]});
    ans += s.size() - 1;
  }
  cout << ans << endl;
  return 0;
}
