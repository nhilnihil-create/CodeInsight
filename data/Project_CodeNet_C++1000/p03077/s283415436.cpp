#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  cout << 5 + (N-1)/min({A,B,C,D,E}) << endl;
}
