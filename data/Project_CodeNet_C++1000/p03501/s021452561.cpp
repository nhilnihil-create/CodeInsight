#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c;
  cin >> a >> b >> c ;
  int d = a*b;
  if (d>=c){
    cout << c << endl;
  }
  if(d<c){
    cout << d << endl;
  }
}