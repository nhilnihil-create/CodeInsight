// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<int, int> P;

int main() {
  int n, k; in(n),in(k);
  map<int, int> M;
  int a;
  loop(i,0,n) {
    in(a);
    M[a]++;
  }
  vector<P> A;
  for (auto&&m : M) {
    A.emplace_back(m.second, m.first);
  }
  sort(A.begin(), A.end());
  int m = A.size();
  int idx = 0;
  ll ans = 0;
  while (m > k) {
    ans += A[idx++].first;
    m--;
  }
  print(ans);
  return 0;
}
