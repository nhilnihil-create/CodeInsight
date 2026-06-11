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

  int mx = 1;
  for(int i = 0; (long long)i * i <= N; i++) {
    long long a = (long long)i * i;
    if (a <= N && mx < a) mx = a;
  }

  cout << mx << endl;

  return 0;
}
