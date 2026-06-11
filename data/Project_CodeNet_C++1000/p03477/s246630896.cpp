#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, D, L, R;
  cin >> A >> B >> C >> D;
  if(!((L=A+B)-(R=C+D)))
    cout << "Balanced" << endl;
  else if(L>R)
    cout << "Left" << endl;
  else
    cout << "Right" << endl;
}