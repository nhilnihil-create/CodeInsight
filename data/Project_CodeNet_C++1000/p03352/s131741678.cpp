#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  
  int ans= 1;
  int base= 2;
  while(base*base <= X){
    int calc= base*base;
    while(calc*base <= X){
      calc*= base;
    }
    ans= max(ans, calc);
    base++;
  }

  cout << ans << endl;
}