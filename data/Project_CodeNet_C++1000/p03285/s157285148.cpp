#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int p = 4, q = 7;
  if(n % 4 == 0){
    cout << "Yes" << endl;
    return 0;
  }
  for(int i = 0;;i++){
    if(n % 7 == 0){
      cout << "Yes" << endl;
      return 0;
    }
    n -= 4;
    if(n <= 0){
      break;
    }
  }
  cout << "No" << endl;
}