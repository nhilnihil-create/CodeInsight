#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long N, M; cin >> N >> M;
  cout << abs((N - 2) * (M - 2)) << "\n";
}