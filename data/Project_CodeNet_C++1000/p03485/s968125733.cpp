#include <bits/stdc++.h>
using namespace std;
int main(){
  double a, b;
  int c;
  cin >> a >> b;
  c = (a+b)/2;
  if((a+b)/2-c==0)
    cout << c << endl;
  else
    cout << c + 1 <<endl;
}