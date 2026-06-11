// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)


inline int nth(int S, int i) {
  return (S>>i)&1;
}

int main() {
  int n, m;
  vector<ll> A[3];
  in(n),in(m);
  loop(i,0,n) {
    loop(j,0,3) {
      ll a; in(a);
      A[j].push_back(a);
    }
  }
  
  ll ans = 0;
  for (int S=0; S<(1<<3); S++) {
    vector<ll> B;
    loop(i,0,n) {
      ll sum = 0;
      loop(j,0,3) {
        if (nth(S, j)) sum += A[j][i];
        else sum -= A[j][i];
      }
      B.push_back(sum);
    }
    sort(B.rbegin(), B.rend());
    ll sum = 0;
    loop(i,0,m) sum += B[i];
    ans = max(sum, ans);
  }
  print(ans);
  return 0;
}
