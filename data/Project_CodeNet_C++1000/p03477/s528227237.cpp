#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D, W;
  cin >> A >> B >> C >> D;

  W = A + B - C - D;
  if (W > 0) cout << "Left" << endl;
  else if (W == 0) cout << "Balanced" << endl;
  else cout << "Right" << endl;

}
