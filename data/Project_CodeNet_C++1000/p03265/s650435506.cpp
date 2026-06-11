#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll X1, Y1, X2, Y2, X3, Y3, X4, Y4;
  cin >> X1 >> Y1 >> X2 >> Y2;
  ll dX = X2 - X1, dY = Y2 - Y1;
  
  X3 = X2 - dY;
  Y3 = Y2 + dX;
  X4 = X1 - dY;
  Y4 = Y1 + dX;
  
  cout << X3 << " " << Y3 << " " << X4 << " " << Y4 << endl;
}