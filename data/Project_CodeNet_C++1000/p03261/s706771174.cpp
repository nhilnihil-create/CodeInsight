// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n; cin >> n;
  vector<string> S(n);
  loop(i,0,n) cin >> S[i];
  char c = S[0][0];
  set<string> S2;
  for (auto&&s: S) {
    if (S2.count(s)) {
      cout << "No" << endl;
      return 0;
    }
    
    if (s[0] != c) {
      cout << "No" << endl;
      return 0;
    }
    c = s[s.size()-1];
    S2.insert(s);
  }
  cout << "Yes" << endl;
  return 0;
}
