#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;
const int INF = 1 << 28;

string to_string(string s) { return s; }

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class T>
string to_string(unordered_set<T> s) {
  string ret = "{";
  for (T t : s) ret += to_string(t) + ",";
  ret += "}";
  return ret;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int D[13], ans[24], fin = 0;

void dfs(int i) {
  if (i == 13) {
    int last = 1, mind = INF;
    FORIN(j, 1, 25) {
      if (ans[j % 24]) {
        mind = min(mind, last);
        last = 1;
      } else {
        last++;
      }
    }
    fin = max(fin, mind);
  } else {
    if (D[i] == 1) {
      ans[i] = 1;
      dfs(i + 1);
      ans[i] = 0;
      ans[24 - i] = 1;
      dfs(i + 1);
      ans[24 - i] = 0;
    } else if (D[i] == 2) {
      ans[i] = 1;
      ans[24 - i] = 1;
      dfs(i + 1);
      ans[24 - i] = 0;
      ans[i] = 0;
    } else {
      dfs(i + 1);
    }
  }
}

int main() {
  int N;
  cin >> N;
  FOR(i, N) {
    int d;
    cin >> d;
    D[d]++;
    if (d == 0 || D[12] > 1 || D[d] > 2) {
      print(0);
      return 0;
    }
  }
  ans[0] = 1;
  dfs(1);
  print(fin);
  return 0;
}
