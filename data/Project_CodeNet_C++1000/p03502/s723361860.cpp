// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  string s; cin >> s;
  int n = stoi(s);
  
  int sum = 0;
  for (auto c: s) {
    sum += c-'0';
  }
  if (n % sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
