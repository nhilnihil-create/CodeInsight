#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int upperPow2(int a) {
  int ret = 2;
  while (ret <= a) {
    ret += ret;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  map<int, int> remain;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++remain[-a];
  }
  int ans = 0;
  for (auto it: remain) { 
    int a = -it.first;
    int c1 = it.second;
    if (c1 == 0) continue;
    int p2 = upperPow2(a);
    int rev = p2-a;
    if (remain.find(-rev) == remain.end()) continue;
    int c2 = remain[-rev];
    if (c2 == 0) continue;
    if (rev == a) {
      if (c2 == 1) continue;
      ans += c2/2;
      remain[-rev] = c2%2;
    }
    else { 
      int c = min(c1, c2);
      remain[-rev] -= c;
      remain[-a] -= c;
      ans += c;
    }
  }
  cout << ans << endl;
}

