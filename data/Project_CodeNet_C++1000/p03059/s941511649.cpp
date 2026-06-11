#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, t;
  cin >> a >> b >> t;
  
  for (int i=1 ; ; i++){
    if (a*i > t){
      cout << b*(i-1) << endl;
      break;
    }
  }
}