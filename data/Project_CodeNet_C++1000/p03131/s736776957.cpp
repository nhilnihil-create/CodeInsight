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
  long long k,a,b;
  cin >> k >> a >> b;
  long long count = k;
  long long over = 0;
  if(b-a <= 1) {
    cout << k+1 << endl;
    return 0;
  }else {
    count -= (a-1);
  }
  if(count % 2 == 0) {
    cout << a + count*(b-a)/2 << endl;
  }else {
    cout << a + (count-1)*(b-a)/2 + 1 << endl;
  }
  return 0;
}
