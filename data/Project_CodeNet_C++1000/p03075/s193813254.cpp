#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  bool have = true;
  if(e - a > k){
    have = false;
  }
  
  if(have){
    cout << "Yay!";
  }
  if(!have){
    cout << ":(";
  }
  return 0;
}