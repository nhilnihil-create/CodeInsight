// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

set<char> S {
  'M', 'A', 'R', 'C', 'H'
};
  
int main() {
  int n; cin >> n;
  map<char, ll> M;
  loop(i,0,n) {
    string s; cin >> s;
    if (!S.count(s[0])) continue;
    M[s[0]]++;
  }
  ll ans = 0;
  string u = "MARCH";
  loop(i,0,3) loop(j,i+1,4) loop(k,j+1,5) {
    ans += M[u[i]] * M[u[j]] * M[u[k]];
  }
  cout << ans << endl;
  return 0;
}
