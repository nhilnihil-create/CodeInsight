// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int max_ = 0;
  loop(k,1,n-1) {
    set<char> S1, S2, S3;
    loop(i,0,k) S1.insert(s[i]);
    loop(i,k,n) S2.insert(s[i]);
    
    for (auto s1: S1) {
      if (S2.count(s1)) S3.insert(s1);
    }
    max_ = max(max_, (int)S3.size());
  }
  cout << max_ << endl;
  return 0;
}
