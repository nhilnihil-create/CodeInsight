#include<bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  cout << 
  min(2*C*max(X,Y), //すべてC
      A*X+B*Y+min(2*C-A-B,0)*min(X,Y))
  << endl;
}