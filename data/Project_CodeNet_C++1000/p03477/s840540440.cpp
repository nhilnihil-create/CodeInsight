#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D,res;
  cin >> A >> B >> C >> D;
  res = (A + B) - (C + D);
  
  if (res > 0){
    cout << "Left" << endl;
  }
  else if(res < 0){
    cout << "Right" << endl;
  }
  else {
    cout << "Balanced" << endl;
  }
}