#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  if(A + B > C + D) cout << "Left" <<endl;
  else if(A + B == C + D) cout << "Balanced" <<endl;
  else cout << "Right" <<endl;
} 
