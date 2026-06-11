#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  cout << 9*max(A,max(B,C)) + A + B + C << endl;
  
}
