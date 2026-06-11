#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int x,y;
  cin >> x >> y;
  int z = x%y;
  if(z==0){
    cout << -1 << endl;
  }
  else {
    cout << x << endl;
  }
}