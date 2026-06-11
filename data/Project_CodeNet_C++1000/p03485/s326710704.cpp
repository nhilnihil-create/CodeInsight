#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  double ave = (a+b)/2;
  if((a+b)%2 == 0){
    cout << ave;
  }
  else{
    cout << ave+1;
  }
}




