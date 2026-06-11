#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,l,r;
  cin >> a >>b >> c >> d;
  l = a+b;
  r = c+d; 
  
  if (l > r){
  	cout << "Left";
  }
  else if (r>l) {
  	cout << "Right";
  }
  else {
  	cout << "Balanced";
  }
}

