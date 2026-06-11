#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

vector<long> a, b, c;

using T = tuple<int, int, int>;

long read() {
  long n;
  cin >> n;
  return n;
}

long value(const T& v) {
  return a[get<0>(v)] + b[get<1>(v)] + c[get<2>(v)];
}

void output(const T& v) {
  cout << value(v) << endl;
}

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;

  for (int i=0; i<x; ++i)
    a.push_back(read());

  for (int i=0; i<y; ++i)
    b.push_back(read());

  for (int i=0; i<z; ++i)
    c.push_back(read());

  vector<long> all;
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  set<T> done;
  priority_queue<pair<long, T>> q;
  T t = {x - 1, y - 1, z - 1};
  q.emplace(value(t), t);

  for (int i = 0; i < k; ++i) {
    long val;
    T t;

    tie(val, t) = q.top();
    q.pop();
    cout << val << endl;

    int u, v, w;
    tie(u, v, w) = t;
    T v1 = {u - 1, v, w};
    T v2 = {u, v - 1, w};
    T v3 = {u, v, w - 1};

    if (!done.count(v1) && u - 1 >= 0) {
      q.emplace(value(v1), v1);
      done.insert(v1);
    }
    if (!done.count(v2) && v - 1 >= 0) {
      q.emplace(value(v2), v2);
      done.insert(v2);
    }
    if (!done.count(v3) && w - 1 >= 0) {
      q.emplace(value(v3), v3);
      done.insert(v3);
    }
    
  }
  
  // for (int i = 0; i < k; ++i) {
  //   output(v);
  //   v = next(v);
  // }
  return 0;
}
