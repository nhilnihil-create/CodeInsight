#include <bits/stdc++.h>
using namespace std;

int main(){
int a, b;
  cin >> a >> b;
  int x;
  x = (a+b)/2;
  if ((a%2 != 0 && b%2 == 0) || (a%2 == 0 && b%2 != 0)){
    cout << x+1 << endl;
  }else {
    cout << x << endl;
  }
}