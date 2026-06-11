#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  
  cin >> N;
  for (int A = 0; A < N && 1 <= N && N <= 100; A++) {
    string S;
    cin >> S;
    
    if (S == "P") {
      i++;
    } else if (S == "W") {
      j++;
    } else if (S == "G") {
      k++;
    } else if (S == "Y") {
      l++;
    }
  }
  if (l == 0) {
    cout << "Three" << endl;
  } else {
    cout << "Four" << endl;
  }
}