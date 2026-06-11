#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,n;
  cin >> n;
  a = n % 10;
  b = (n % 100 - a) /10;
  c = (n % 1000 - b*10 - a ) /100;
  d = (n -c*100 -b*10 -a)/1000;
  
  if ((a==b && b==c) || (b==c && c==d)  ){
  	cout << "Yes";
  }
  else {
  	cout << "No";
  }
}

