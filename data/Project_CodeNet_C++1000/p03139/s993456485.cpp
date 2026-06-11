#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int n,x,y;
  cin >> n >> x >> y;
  cout << min(x,y) << " ";
  if(x+y<=n) {
    cout << 0 << endl;
  }
  else {
    cout << x+y-n << endl;
  }
}