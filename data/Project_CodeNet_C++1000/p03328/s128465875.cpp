#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int delta = b - a;
  
  int A = 0;
  for (int i=1; i<delta ; i++)
    A += i;
  
  cout << A - a << endl;
}