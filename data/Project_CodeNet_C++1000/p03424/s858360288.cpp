#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

int main(int argc, char* argv[]) {
  cin >> N;
  bool has_yellow = false;
  for (int i = 0; i < N; i++) {
    char S;
    cin >> S;
    if (S == 'Y')
      has_yellow = true;
  }

  cout << (has_yellow ? "Four" : "Three") << endl;
  return 0;
}
