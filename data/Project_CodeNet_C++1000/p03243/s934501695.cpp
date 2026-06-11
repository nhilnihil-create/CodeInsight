#include <iostream>
#include <string>

using namespace std;

int main() {
  string N;
  cin >> N;
  string target = "";
  for (size_t i = 0; i < N.size(); ++i) {
    target += N[0];
  }
  int n = stoi(N);
  int t = stoi(target);
  if (n == t) {
    cout << N << endl;
    return 0;
  } else if (n < t) {
    cout << t << endl;
  } else {
    char c = N[0] + 1;
    for (size_t i = 0; i < N.size(); ++i) {
      cout << c;
    }
    cout << endl;
  }
  return 0;
}
