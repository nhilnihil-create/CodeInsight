#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int K = S.size();
  bool check = true;
  if (K == 1) {
    cout << S << endl;
    return 0;
  }
  for (int i = 1; i < K; i++) {
    if (S[i] != '9') {
      check = false;
    }
  }
  if (check) { //  Nが、○999...999の形
    int top = (S[0] - '0');
    cout << top + 9*(K-1) << endl;
  }
  else {
    int top = (S[0] - '0');
    cout << top -1 + 9*(K-1) << endl;
  }
}

    
    
      