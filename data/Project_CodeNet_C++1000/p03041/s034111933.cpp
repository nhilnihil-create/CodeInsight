#include <iostream>
#include <string>

using namespace std;

namespace {
constexpr char diff = 'A' - 'a';
}

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  --K;
  S[K] = S[K] - diff;
  
  cout << S << endl;
  
  return 0;
}
