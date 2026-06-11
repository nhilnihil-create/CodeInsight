#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b ;
  c=(a+b)/2;
  if (c*2 != a+b){
    c++;
  }
  cout << c << endl;
}