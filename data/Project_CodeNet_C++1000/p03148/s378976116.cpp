#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>

using std::cin;
using std::cout;
using std::endl;
using std::unordered_set;
using std::pair;
using std::stack;
using std::string;
using std::vector;

int main(int argc, char* argv[]) {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> ss(n);
  for (int i = 0; i < n; ++i) {
    int t, d;
    cin >> t >> d;
    ss[i] = std::make_pair(t, d);
  }

  sort(ss.begin(), ss.end(), [](const pair<int, int>& s1, const pair<int, int>& s2) {
      return s1.second > s2.second;
    });

  stack<pair<int, int>> ds;  // duplicated sushis
  unordered_set<int> ts;  // toppings;

  unsigned long max_satisfaction = 0;
  for (int i = 0; i < k; ++i) {
    if (ts.find(ss[i].first) == ts.end()) {
      ts.insert(ss[i].first);
    } else {
      ds.push(ss[i]);
    }
    max_satisfaction += ss[i].second;
  }
  max_satisfaction += ts.size() * ts.size();

  unsigned long satisfaction = max_satisfaction;
  for (int i = k; i < n; ++i) {
    if (ds.empty()) {
      break;
    }
    if (ts.find(ss[i].first) != ts.end()) {
      continue;
    }
    satisfaction = satisfaction + (ss[i].second - ds.top().second)
      + (ts.size() + 1) * (ts.size() + 1) - ts.size() * ts.size();
    if (satisfaction > max_satisfaction) {
      max_satisfaction = satisfaction;
    }
    ts.insert(ss[i].first);
    ds.pop();
  }

  cout << max_satisfaction;

  return 0;
}
