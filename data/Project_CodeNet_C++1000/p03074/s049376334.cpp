// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]" << endl;  return os;  }
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> A;
  if (s[0] == '0') A.push_back(0);
  char prev = ' ';
  for (auto &&c: s) {
    if (prev != c) {
      A.push_back(0);
      prev = c;
    }
    A[A.size()-1]++;
  }
  if (s[n-1] == '0') A.push_back(0);
  int m = A.size();
  vector<int> acc(m+1, 0);
  loop(i,0,m) acc[i+1] = acc[i] + A[i];
  int len = min(2*k+1, m);
  int max_ = 1;
  for (int l=0; l+len<=m; l++) {
    if (l%2==1) continue;
    max_ = max(max_, acc[l+len] - acc[l]);
  }
  cout << max_ << endl;
  return 0;
}
