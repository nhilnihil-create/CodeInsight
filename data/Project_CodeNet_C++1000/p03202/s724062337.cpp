#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef pair<int,int> pii;
typedef pair<i64,int> pli;
typedef pair<int,i64> pil;
typedef pair<i64,i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;

template <typename T>
T id(T b) {return b;};
template <class It>
bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It>
bool any(It f,It l){return std::any_of(f,l,id<bool>);}

const int MAX_N = 200000;
int n;
int a[MAX_N];

bool f(int k)
{
  map<int,int> m;
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i-1]) {
      while (!m.empty() && m.rbegin()->first > a[i]) {
        m.erase(m.rbegin()->first);
      }

      m[a[i]]++;
      int j = a[i];
      while (j > 1 && m[j] == k) {
        m.erase(j);
        m[--j]++;
      }
      if (j == 1 && m[1] == k)
        return false;
    }
  }
  return true;
}

int main()
{
  bool inc = true;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) inc &= a[i] > a[i-1];
  }

  if (inc) {
    cout << 1 << endl;
    return 0;
  }

  int l = 1, r = n+1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (f(m))
      r = m;
    else
      l = m;
  }

  cout << r << endl;

  return 0;
}
