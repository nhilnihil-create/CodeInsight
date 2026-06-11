#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  if (N == 1) {
    cout << "Hello World" << endl;
    return 0;
  }

  int A, B; cin >> A >> B;
  cout << A + B << endl;
}
