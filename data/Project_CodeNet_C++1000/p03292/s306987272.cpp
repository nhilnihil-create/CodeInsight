#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(3);
  for(int i=0; i<3; i++) {
      cin >> A.at(i);
  }
  int a = abs(A.at(0) - A.at(1));
  int b = abs(A.at(1) - A.at(2));
  int c = abs(A.at(0) - A.at(2));
  cout << min({a+b,a+c,b+c}) << endl;
}
