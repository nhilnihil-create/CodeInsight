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
  int A, B, C;
  cin >> A >> B >> C;

  if (A <= C && C <= A+B) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
