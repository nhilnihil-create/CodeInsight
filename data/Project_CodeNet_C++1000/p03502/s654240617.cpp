#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x,temp;
  int f = 0;
  cin >> n;
  x = n;
  for(int i=8;i>=0;i--) {
    temp = pow(10,i);
    if(n/temp!=0) {
      f += x/temp;
      x -= temp * (x/temp);
    }
  }
  if(n%f==0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}