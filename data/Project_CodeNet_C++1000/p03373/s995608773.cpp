#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  c = 2*c;
  long long min = 1000000000000;
  for (int i=0; i<=x; i++){
    int cost=0;
    if(y>x-i) cost = a*i + (x-i)*c + (y-(x-i))*b;
    else cost = a*i + (x-i)*c;
    min = cost<min?cost:min;
  }
  for (int j=0; j<=y; j++){
    int cost=0;
    if(x>y-j) cost = b*j + (y-j)*c + (x-(y-j))*a;
    else cost = b*j + (y-j)*c;
    min = cost<min?cost:min;
  }
  cout << min << endl;
}