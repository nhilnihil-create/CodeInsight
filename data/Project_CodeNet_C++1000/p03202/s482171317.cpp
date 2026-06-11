#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

template <typename T>
void debug_out(T t) {
  cerr << t;
}

template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}

template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << ", ";
  }
}

template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for(int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if(i != sz - 1) cerr << endl;
  }
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << endl, debug_out(__VA_ARGS__), cerr << endl;


int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> a(n);
  range(i, 0, n) {
    cin >> a[i];
  }
  bool easy = true;
  range(i, 1, n) {
    easy &= a[i] > a[i - 1];
  }
  if(easy) {
    cout << 1;
    return 0;
  }
  vector<pair<int, int>> one;
  vector<pair<int, int>> other;
  auto solve = [&](int s) {
    one.clear(); other.clear();
    one.emplace_back(0, a[0] - 1);
    range(i, 1, n) {
      if(a[i] > a[i - 1]) {
        if(one.size() && one.back().second == a[i - 1] - 1) one.back().second = a[i] - 1;
        else one.push_back(make_pair(a[i - 1], a[i] - 1));
        continue;
      }
      while(one.size() && one.back().first >= a[i]) one.pop_back();
      if(one.size()) one.back().second = min(one.back().second, a[i] - 1);
      while(other.size() && other.back().first >= a[i]) other.pop_back();
      if(one.empty() && other.empty()) {
        return false;
      }
      int pos = INT_MIN;
      if(one.size()) pos = one.back().second;
      if(other.size()) pos = max(pos, other.back().first);
      if(one.size() && one.back().second == pos) {
        one.back().second--;
        if(one.back().second < one.back().first) one.pop_back();
        if(s > 2) other.emplace_back(pos, 2);
      } else {
        other.back().second++;
        if(other.back().second == s) other.pop_back();
      }
      if(pos + 1 < a[i]) one.emplace_back(pos + 1, a[i] - 1);
    }
    return true;
  };
  int lo = 1, hi = n;
  while(hi - lo > 1) {
    int mid = (hi + lo) >> 1;
    if(solve(mid)) hi = mid;
    else lo = mid;
  }
  cout << hi;
  return 0;
}
