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
  int N;
  cin >> N;
  int A;
  cin >> A;

  N %= 500;
  if (N <= A) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
