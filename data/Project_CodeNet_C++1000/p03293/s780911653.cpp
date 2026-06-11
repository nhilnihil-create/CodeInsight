#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  rep(i, 0, (int)s.size()+1) {
    int f = 0;
    rep(j, 0, (int)s.size()) {
      if(s[j] != t[(i+j)%(int)s.size()]) {
        f = 1;
        break;
      }
    }
    if(f == 0) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}
