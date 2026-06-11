#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
	}
  s << "]";
	return s;
}

// Supports two operations.
// - Updates a single element.
// - Returns a sum of a range.
// Verified: CF573Div1D
class BinaryIndexedTree {
 private:
  int n;
  vector<int> xs;
 public:
  BinaryIndexedTree(int n) : n(n), xs(n) {}

  // Adds x to the i-th element.
  void Add(int i, int x) {
    int cur = i;
    while (cur < n) {
      xs[cur] += x;
      cur = cur | (cur + 1);
    }
  }

  // Returns a sum of a range [l r).
  int SumOfRange(int l, int r) {
    if (l >= r) return 0;
    if (l > 0) {
      return SumOfRange(0, r) - SumOfRange(0, l);
    }
    int s = 0;
    int i = r - 1;
    while (i >= 0) {
      s += xs[i];
      i = (i & (i + 1)) - 1;
    }
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  auto is_valid = [&](int k) {
    if (DEBUG) cout << "k: " << k << endl;

    vector<int> signs(n);
    for (int i = 0; i < n; i++) {
      if (xs[i] >= k) signs[i] = 1;
      else signs[i] = -1;
    }
    vector<int> cs(n + 1);
    for (int i = 0; i < n; i++) {
      cs[i + 1] = cs[i] + signs[i];
    }

    if (DEBUG) cout << "signs: " << signs << endl;
    if (DEBUG) cout << "cs: " << cs << endl;

    BinaryIndexedTree bit(2 * n + 1);
    int64 count = 0;
    for (int i = n; i >= 0; i--) {
      int c = cs[i];
      count += bit.SumOfRange(n + c, 2 * n + 1);
      bit.Add(n + c, 1);
    }

    if (DEBUG) cout << "count: " << count << endl;

    int64 n64 = n;
    int64 total = n64 * (n64 + 1) / 2;
    return count >= (total + 1) / 2;
  };

  int l = 0;
  int r = 1 << 30;
  while (r - l >= 2) {
    int m = (l + r) / 2;
    if (is_valid(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
}