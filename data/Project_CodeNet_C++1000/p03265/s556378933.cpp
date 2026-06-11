#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int p = c - a, q = d - b;
  cout << c - q << " " << d + p << " " << a - q << " " << b + p << endl;
}