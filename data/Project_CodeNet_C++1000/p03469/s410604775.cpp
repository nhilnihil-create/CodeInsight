// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve();
int main() { solve(); return 0; }

#include <set>
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  loop(i,0,n) {
    if (i==3) cout << 8;
    else cout << s[i];
  }
  cout << endl;
}
