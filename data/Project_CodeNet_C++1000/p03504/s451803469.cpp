/*
 * atcoder/abc080/d.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v) { cout << v << endl; }
template <typename T> void in(T &v) { cin >> v; }
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<int, bool> P;
vector<pair<int, int> > B;
vector<pair<int, int> > A[30];
vector<P> D;

int main() {
  int N, C;in(N),in(C);
  {
    loop(i,0,N) {
      int s, t, c; in(s),in(t),in(c);
      c--;
      A[c].emplace_back(s, t);
    }

    loop(i,0,C) {
      sort(A[i].begin(), A[i].end());
      int m = A[i].size();
      loop(j,0,m) {
        auto a = A[i][j];
        if (j==0) {
          B.push_back(a);
          continue;
        }

        auto &b_last = B.back();
        if (b_last.second == a.first) {
          b_last.second = a.second;
          continue;
        }

        B.push_back(a);
      }
    }
  }

  {
    for (auto b: B) {
      D.emplace_back(b.first, false);
      D.emplace_back(b.second, true);
    }
    sort(D.begin(), D.end());
  }

  int cnt = 0;
  int ans = 0;
  for (auto &&d: D) {
    if (!d.second) {
      ans = max(ans, ++cnt);
    } else {
      cnt--;
    }
  }
  print(ans);
  return 0;
}
