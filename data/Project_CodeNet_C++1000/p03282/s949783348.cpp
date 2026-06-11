#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long long K;
  cin >> S >> K;
  int count = 0;
  
  vector<char>C(S.size());
  for (int i = 0; i < S.size(); i++) {
    C.at(i) = S.at(i);
    if (C.at(i) == '1' && i < K){
      count++;
    }
  }
  if (count == K){
    cout << 1 << endl;
    return 0;
  }
  
  for (int i = 0; i < S.size(); i++) {
    if (C.at(i) != '1'){
      cout << C.at(i) << endl;
      break;
    }
  }
}