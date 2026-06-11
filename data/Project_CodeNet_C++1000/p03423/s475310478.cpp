#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  for (int i=0 ; ; i++){
    if (n < 3){
      cout << i << endl;
      break;
    }
    n -= 3;
  }
}