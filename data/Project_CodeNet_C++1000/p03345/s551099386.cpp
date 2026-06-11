#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>
#include <stack>
#include <sstream>

using namespace std;
const long long P = 1000000007;
const long long INF = 1LL << 60;

int main() {
  long long a,b,c,k;
  cin >> a >> b >> c >> k;
  if(k % 4 == 1 || k % 4 == 3) {
    cout << b-a << endl;
  }else if(k % 4 == 2 || k % 4 == 0) {
    cout << a-b << endl;
  }
  return 0;
}
