#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  long Wnum = 0;
  long cnt = 0;
  for (size_t i=0; i<S.size(); i++) {
    if (S[i] == 'W') {
      Wnum += i - cnt;
      cnt++;
    }
  }
  cout << Wnum << endl;
}


