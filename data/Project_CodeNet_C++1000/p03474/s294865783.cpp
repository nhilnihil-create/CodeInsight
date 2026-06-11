// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve(); int main() { solve(); return 0; }

void solve() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  int i=0;
  while (i<a) {
    if (s[i++] == '-') {
      cout << "No" << endl;
      return;
    }
  }
  if (s[i++] != '-') {
    cout << "No" << endl;
    return;
  }
  b += 1 + a;
  while (i<b) {
    if (s[i++] == '-') {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
