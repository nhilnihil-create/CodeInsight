#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

  int a,b,t;
  cin >> a >> b >> t;
  int x,y,z;
  x=t%a;
  y=(t-x)/a;
  z=y*b;
  cout << z << endl;
}