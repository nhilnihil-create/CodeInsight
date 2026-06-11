#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N, A;
  cin >> N >> A;
  if (N % 500 <= A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
