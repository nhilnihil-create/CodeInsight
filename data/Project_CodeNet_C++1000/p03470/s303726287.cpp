#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  set<int> s;
  FOR(i,0,N) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << s.size() << endl;
    
  return 0;
}

