#include <bits/stdc++.h>

const int MOD = 1000000007;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define copy(from, to) copy(from.begin(), from.end(), back_inserter(to))
#define sort(a) sort(a.begin(), a.end())
#define reverse(s) reverse(s.begin(), s.end())
#define p(s) cout << (s) << endl

typedef long long ll;
using namespace std;

template<class T>
void load(vector<T> &v, int n) {
  for (int i = 0; i < n; ++i) {
    T t;
    cin >> t;
    v.push_back(t);
  }
}

template<class T>
T max(vector<T> &v) {
  return *max_element(v.begin(), v.end());
}

template<class T>
T min(vector<T> &v) {
  return *min_element(v.begin(), v.end());
}

void py(bool isUpper = false) {
  if (isUpper) {
    p("YES");
  } else {
    p("Yes");
  }
}

void pn(bool isUpper = false) {
  if (isUpper) {
    p("NO");
  } else {
    p("No");
  }
}

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  for (int i = 1; i <= k; ++i) {
    if (i % 2 == 1) {
      //高橋くんパート
      if (a % 2 == 1) {
        a--;
      }
      b += a / 2;
      a /= 2;
    } else {
      if (b % 2 == 1) {
        b--;
      }
      a += b / 2;
      b /= 2;
    }
  }

  cout << a << " " << b << endl;
}