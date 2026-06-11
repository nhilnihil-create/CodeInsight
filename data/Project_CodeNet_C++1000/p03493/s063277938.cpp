#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  int sum = 0;
  cin >> a;
  if(a/100 == 1){
    sum++;
    a-= 100;
  }
  if(a/10 == 1){
    sum++;
    a -= 10;
  }
  if(a/1 == 1){
    sum++;
  }

  
  
  cout << sum << endl;
  
}