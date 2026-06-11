#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
  int X = stoi(N);
  int fX;
  for(int i=0; i<N.size(); i++) {
   fX += (int)(N.at(i) - '0');
  }
  if(X % fX == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}