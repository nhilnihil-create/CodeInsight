#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int E=C-A,F=D-B;
  
  cout << C-F << " " << D+E  << " " << C-F-E << " " << D+E-F  << " " << endl;
}