#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  int n,k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans;
  if((n-1) % (k-1) == 0) {
    ans = (n-1)/(k-1);
  }else {
    ans = (n-1)/(k-1)+1;
  }
  cout << ans << endl;
  return 0;
}
