#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<string> words;
  vector<string> memo;
  rep(i, n) {
    string s;
    cin >> s;
    words.push_back(s);
  }
  memo.push_back(words[0]);
  bool flag = true;
  for (int i = 1; i < n; i++) {
    char a, b;
    a = words[i - 1][words[i - 1].size() - 1];
    b = words[i][0];
    if (a == b) {
      rep(j, memo.size()) {
        if (words[i] == memo[j])
          flag = false;
      }
    } else {
      flag = false;
    }
    if (flag)
      memo.push_back(words[i]);
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
