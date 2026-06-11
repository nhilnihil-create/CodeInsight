#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using lli = long long int;

constexpr int K = 6;

struct Num {
  string prefix, suffix;
  char fill;
  int fill_lenght;

  Num() : Num("") { }
  Num(string p) : Num(p, ' ', 0) { }
  Num(string p, char f, int fl): fill(f), fill_lenght(fl) {
    if (f == ' ') prefix = p;
    else {
      for (int i = 0; i < p.size(); ++i) {
        if (p[i] >= fill) prefix += p[i];
        else suffix += p[i];
      }
    }
  }

  int size() const { return prefix.size() + fill_lenght + suffix.size(); }
  char at(int p) const {
    if (p < prefix.size()) return prefix[p];
    if (p >= prefix.size() + fill_lenght) return suffix[p - fill_lenght - prefix.size()];
    return fill;
  }

  bool operator<(const Num& rhs) const {
    if (size() < rhs.size()) return true;
    if (size() == rhs.size()) {
      for (int i = 0; i < min(K + 2, size()); ++i) {
        if (at(i) == rhs.at(i)) continue;
        return at(i) < rhs.at(i);
      }
      for (int i = max(K + 2, size() - K - 2); i < size(); ++i) {
        if (at(i) == rhs.at(i)) continue;
        return at(i) < rhs.at(i);
      }
    }
    return false;
  }

  void print() {
    cout << prefix;
    for (int i = 0; i < fill_lenght; ++i) cout << fill;
    cout << suffix;
  }
};

vector<int> a;
vector<int> costs = {0, 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};

Num solve(int n, string pattern) {
  Num result;
  if (n < 0) return result;
  for (auto it = a.begin(); it < a.end(); ++it) {
    int cost = costs[*it];
    if (n % cost == 0) {
      result = max(result, Num(pattern, '0' + *it, n / cost));
    }
  }
  if (pattern.size() > K) return result;
  for (auto it = a.begin(); it < a.end(); ++it) {
    int cost = costs[*it];
    string tmp = pattern;
    result = max(result, solve(n - cost, tmp + to_string(*it)));
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  map<int, int> tmp;
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    tmp[costs[t]] = max(tmp[costs[t]], t);
  }
  for (auto p : tmp) a.push_back(p.second);
  sort(all(a));
  reverse(all(a));
  solve(n, "").print();
  return 0;
}