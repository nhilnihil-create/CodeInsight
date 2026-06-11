#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  string S; cin >> S;
  int T = S.size();
  for(int k = 0; k < S.size() - 1; k++) {
    if(S[k] != S[k+1]) T = min(T, max(k+1, (int)S.size()-k-1));
  }
  cout << T << endl;

  return 0;
}
