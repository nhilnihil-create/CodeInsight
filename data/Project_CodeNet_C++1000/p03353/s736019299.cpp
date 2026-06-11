#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  int K; cin >> K;

  set<string> st;
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < min(5, (int)s.size()); j++)
      if (i+j < s.size()) st.insert(s.substr(i, j+1));
  int count = 0;
  for (string ans : st) {
    if (++count == K) {
      cout << ans << "\n";
      break;
    }
  }
}