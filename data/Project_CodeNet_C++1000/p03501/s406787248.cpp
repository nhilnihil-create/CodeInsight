#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin >> n >> a >> b;

  if((n*a)<b){
    cout << n*a <<"\n";
  } else {
    cout << b <<"\n";
  } 
  
  return(0);
}
