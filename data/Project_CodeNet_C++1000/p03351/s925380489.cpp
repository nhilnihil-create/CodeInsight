#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool ok = (abs(a-c)<=d) || (abs(a-b)<=d&&abs(b-c)<=d);
  cout << (ok?"Yes":"No") << endl;
}
