#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int x = a + b;
  
  if (x%2 == 0)
    cout << x/2 << endl;
  else
    cout << (x+1)/2 << endl;
}