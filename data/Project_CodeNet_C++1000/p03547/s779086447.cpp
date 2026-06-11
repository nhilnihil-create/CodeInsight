#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  char x, y;
  cin>>x>>y;
  if(x>y) cout << '>';
  if(x<y) cout << '<';
  if(x==y) cout <<'=';
  cout << endl;
}