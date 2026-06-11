#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int N,A;
  std::cin >> N>>A;
  if (N%500<=A) {
    std::cout << "Yes" << '\n';/* code */
  }
  else {
    std::cout << "No" << '\n';
  }
  return 0;
}
