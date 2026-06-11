#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int A, B;
string S;

int main(int argc, char* argv[]) {
  cin >> A >> B >> S;

  for (int i = 0; i < S.size(); i++) {
    if (i == A && S[i] != '-') {
      cout << "No" << endl;
      return 0;
    }

    if (i != A && S[i] < '0' || '9' < S[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
