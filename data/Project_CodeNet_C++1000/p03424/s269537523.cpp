#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int P, W, G, Y;
  P = W = G = Y = 0;
  
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (S == "P") P++;
    else if (S == "W") W++;
    else if (S == "G") G++;
    else Y++;
  }
  if (Y) cout << "Four" << endl;
  else cout << "Three" << endl;  
}
