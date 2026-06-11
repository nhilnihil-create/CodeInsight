#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string N_str = to_string(N);

  int fX = 0;
  for (int i = 0; i < N_str.length(); i++) {
    fX += (int) N_str[i] - 48;
  }
  
  if (N % fX == 0) 
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
