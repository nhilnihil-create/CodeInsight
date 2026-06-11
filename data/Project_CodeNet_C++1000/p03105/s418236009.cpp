#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int n;
  for (int i=1 ; ; i++){
    if (a*i > b){
      n = i-1;
      break;
    }
  }
  
  if (n > c)
    cout << c << endl;
  else
    cout << n << endl;
}