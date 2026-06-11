#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if(A == B) cout << C << endl;
  else if(A == C) cout << B << endl;
  else cout << A << endl;
}