#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using Entry = pair<string, int>;

int main() {
  string s;
  int K;
  cin >> s >> K;
  auto comp = [](const auto& a, const auto& b) { return a.first > b.first; };
  priority_queue<Entry, vector<Entry>, decltype(comp)> qs(comp);
  for(int i = 0; i < s.size(); ++i) {
    qs.push(make_pair(s.substr(i, 1), i)); //
  }
  map<string, int> ck;
  while(!qs.empty()) {
    auto crnt = qs.top();
    qs.pop();
    // cout << crnt.first << " len:" << crnt.first.length() << endl;

    auto v = s.substr(crnt.second, crnt.first.length());
    ck[v]++;
    // cout << v << "," << ck[v] << endl;

    if(ck.size() == K) {
      cout << v << endl;
      return 0;
    }
    if(crnt.second + crnt.first.length() + 1 <= s.size()) {
      auto next = s.substr(crnt.second, crnt.first.length() + 1);
      qs.push(make_pair(next, crnt.second));
    }
  }

  return 0;
}