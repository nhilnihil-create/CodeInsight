// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n;in(n);
  vector<ll> C(200, 0);
  string s;
  loop(i,0,n) {
    in(s);
    C[(int)s[0]]++;
  }
  vector<ll> A;
  ll ans = 0;
  string t = "MARCH";
  loop(i,0,3) loop(j,i+1,4) loop(k,j+1,5) {
    ans += C[t[i]] * C[t[j]] * C[t[k]];
  }
  print(ans);
  return 0;
}
