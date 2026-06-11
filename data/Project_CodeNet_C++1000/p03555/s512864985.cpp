#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  bool ok=true;
  if(a[0]!=b[2]) ok=false;
  if(a[1]!=b[1]) ok=false;
  if(a[2]!=b[0]) ok=false;
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
}