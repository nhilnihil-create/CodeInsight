#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
using I = pair<int, int>;
using Compare = function<bool(int, int)>;
#define fst first
#define snd second

vector<I> func(const vector<I>& is, int p) {
  auto lcmp = [&](int i, int j) {
    if (is[i].snd != is[j].snd) return is[i].snd < is[j].snd;
    return i < j;
  };
  auto rcmp = [&](int i, int j) {
    if (is[i].fst != is[j].fst) return is[i].fst > is[j].fst;
    return i < j;
  };

  set<int, Compare> L(lcmp), R(rcmp);
  for (int i = 0; i < is.size(); i++) {
    L.insert(i);
    R.insert(i);
  }
  set<int, Compare> S[2] = {L, R};
  vector<I> ans;
  while (ans.size() < is.size()) {
    int i = *S[p].begin();
    ans.push_back(is[i]);
    S[0].erase(i);
    S[1].erase(i);
    p ^= 1;
  }
  return ans;
}

ll calcCost(const vector<I>& is) {
  ll ans = 0;
  int p = 0;
  for (const I& i : is) {
    if (i.fst <= p && p <= i.snd) {
      continue;
    }
    if (p < i.fst) {
      ans += i.fst - p;
      p = i.fst;
    } else {
      ans += p - i.snd;
      p = i.snd;
    }
  }
  ans += abs(p);
  return ans;
}

int main() {
  int N;
  while (cin >> N) {
    vector<I> is(N);
    for (int i = 0; i < N; i++) cin >> is[i].first >> is[i].second;
    ll ans = max(calcCost(func(is, 0)), calcCost(func(is, 1)));
    cout << ans << endl;
  }
  return 0;
}
