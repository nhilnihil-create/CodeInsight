#include <bits/stdc++.h>
using namespace std;

int main(){
  int R,G;
  
  cin >> R;
  cin >> G;
  
  if (0 <= R, G<= 4500){
    cout << 2*G-R << endl;
  }
  else {
    cout << "error" << endl;
  }
}