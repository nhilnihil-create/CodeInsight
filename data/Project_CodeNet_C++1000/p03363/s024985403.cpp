#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int main() {
  ll N, A, t{}, ans{};
  cin >> N;
  map<ll, int> m;
  ++m[0];
  while (cin >> A) {
    t += A;
    ans += m[t]++;
  }
  cout << ans << endl;
}
