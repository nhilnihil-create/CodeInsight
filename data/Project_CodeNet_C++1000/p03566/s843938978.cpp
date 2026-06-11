#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define P pair<int, int>
#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define GI(name) \
  int(name);     \
  scanf("%d", &(name))
#define GI2(name1, name2) \
  int(name1), (name2);    \
  scanf("%d %d", &(name1), &(name2))
#define GI3(name1, name2, name3) \
  int(name1), (name2), (name3);  \
  scanf("%d %d %d", &(name1), &(name2), &(name3))
#define GVI(name, size)    \
  vector<int>(name)(size); \
  FOR(i, (size)) scanf("%d", &(name)[i])
#define GS(name) \
  string(name);  \
  cin >> (name);
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  FOR(i, v.size() - 1) { ret += to_string(v[i]) + ","; }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() {
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int main() {
  GI(N);
  GVI(t, N);
  GVI(v, N);
  int len = accumulate(ALL(t), 0);
  debug(t, v, len);
  vector<double> vs(len * 2 + 1, 100);
  int start = 0, end = 0;
  FOR(i, N) {
    end += t[i];
    for (int x = 0; x < len * 2 + 1; ++x) {
      if (start * 2 <= x && x < end * 2 + 1) {
        vs[x] = min(vs[x], (double)v[i]);
      } else if (x < start * 2) {
        vs[x] = min(vs[x], (double)v[i] + (start * 2 - x) / 2.0);
      } else {
        vs[x] = min(vs[x], (double)v[i] + (x - end * 2) / 2.0);
      }
    }
    start = end;
  }
  for (int x = 0; x < len * 2 + 1; ++x) {
    vs[x] = min(vs[x], (double)(x) / 2.0);
    vs[x] = min(vs[x], (double)(len * 2 - x) / 2.0);
  }
  debug(vs);
  double ans = 0;
  for (int x = 0; x < len * 2 + 1; ++x) {
    ans += (vs[x] + vs[x + 1]) * 0.25;
  }
  print(ans);
  return 0;
}