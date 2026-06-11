#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B, K;
  cin >> A >> B >> K;

  for (int i = A; i <= B; i++) {
    if (i <= A + K - 1 || i >= B - K + 1) cout << i << endl;
  }
  
  return 0;
}
