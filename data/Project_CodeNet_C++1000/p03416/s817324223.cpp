#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, y = 0;
  string x;
  cin >> A >> B;
  while(A <= B){
    x = to_string(A);
    if(x[0] == x[4] && x[1] == x[3]){
      y++;
    }
    A++;
  }
  cout << y << endl;
}
