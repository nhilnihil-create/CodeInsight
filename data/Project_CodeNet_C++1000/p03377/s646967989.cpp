#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int A, B, X;
  cin >> A >> B >> X;
  
  if(A <= X && A + B >= X ) cout << "YES" << endl;
  else cout << "NO" << endl;
}