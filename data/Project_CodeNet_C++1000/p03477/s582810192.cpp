#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int l_plate= a + b;
  int r_plate= c + d;
  if (r_plate < l_plate){
    cout << "Left" << endl;
  }
  else if (r_plate > l_plate){
    cout << "Right" << endl;
  }
  else{
    cout << "Balanced" << endl;
  }
}
