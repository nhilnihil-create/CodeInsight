#include <bits/stdc++.h>
using namespace std;

int N;
set<string> SE;

void dfs(string s) {
  if (s.size() && stol(s) > N) return;
  if (s.size()) {
    string t = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    if (t.size() == 3) SE.insert(s);
  }
  dfs('7' + s);
  dfs('5' + s);
  dfs('3' + s);
}

int main() {
  cin >> N;
  string start;
  dfs(start);
  cout << SE.size() << "\n";
}