#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  string s;
  cin >> n;
  vector<string> word(200,"");
  vector<int> count(200,0);
  for (int i = 0; i < n; i++) {
    cin >> s;
    for(int j = 0; j < 200; j++) {
      if (s == word.at(j)) {
        count.at(j) += 1;
        break;
      } else if (word.at(j) == "") {
        word.at(j) = s;
        count.at(j) += 1;
        break;
      }
    }
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> s;
    for (int j = 0; j < 200; j++) {
      if (s == word.at(j)) {
        count.at(j) -= 1;
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 200; i++) {
    if (ans < count.at(i)) {
      ans = count.at(i);
    }
    //cout << word.at(i) << " " << count.at(i) << endl;
  }
  cout << ans << endl;
}