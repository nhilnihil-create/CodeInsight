#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  cout << (N < 1000 ? "ABC" : "ABD") << "\n";
}