#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if(A == B && A == C && B == C) cout << "Yes" << endl;
  else cout << "No" << endl;
}