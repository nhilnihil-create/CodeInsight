#include <bits/stdc++.h>
using namespace std;

int main(){
  int left1 , left2 , right1 , right2;
  cin >> left1 >> left2 >> right1 >> right2;
  
  if(left1 + left2 > right1 + right2){
    cout << "Left" << endl;
  }
  else if(left1 + left2 < right1 + right2){
    cout << "Right" << endl;
  }
  else{
    cout << "Balanced" << endl;
  }
}