#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  float c;
  int x;
  cin >> a >> b;
  c=(a+b)/2;
  if((a+b)%2==0){
    x=c;
    cout << x << endl;
  }else{
    x=(a+b)/2+1;
    cout << x << endl;
  }
 }

