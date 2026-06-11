#include <iterator>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv) {
  int A, B, K;
  cin >> A >> B >> K;
  int i = max(A, B);
  int k = 0;
  while (true) {
    if (A % i == 0 && B % i == 0) {
      ++k;
      if (k == K) {
        cout << i << endl;
        return 0;
      }
    }
    --i;
  }
  return 0;
}