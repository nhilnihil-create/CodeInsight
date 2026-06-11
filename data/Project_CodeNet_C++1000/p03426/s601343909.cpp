// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll h,w,d; in(h), in(w), in(d);
  int n=h*w;
  vector<int> X(h*w+1),Y(h*w+1);
  loop(y,1,h+1) loop(x,1,w+1) {
    int a; in(a);
    X[a] = x;
    Y[a] = y;
  }
  ll q;in(q);
  vector<ll> dp(n+1, 0);
  for (int i=n; i>=1; i--) {
    if (i+d > n) continue;
    dp[i] = dp[i+d] + abs(X[i] - X[i+d]) + abs(Y[i] - Y[i+d]);
  }
  
  loop(i,0,q) {
    ll l, r; in(l),in(r);
    print(dp[l]-dp[r]);
  }
  return 0;
}
