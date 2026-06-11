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

vector<string> Z { "NO", "YES" };

#include <set>
void solve() {
  string s, t;
  cin >> s >> t;
  s += t;
  string u = s;
  reverse(u.begin(), u.end());  
  cout << Z[s == u] << endl;
}
