// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
void solve(); int main() { solve(); return 0; }

void solve() {
  string s; cin >> s;
  sort(s.begin(), s.end());
  if (s == "abc") cout << "Yes" << endl;
  else cout << "No" << endl;
}
