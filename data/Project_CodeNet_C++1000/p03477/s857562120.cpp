#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int x = A + B;
  int y = C + D;
  if (x > y){
    cout << "Left" << endl;
  }
  else if (x == y){
	cout << "Balanced" << endl;
  }
  else{
    cout << "Right" << endl;
  }
}