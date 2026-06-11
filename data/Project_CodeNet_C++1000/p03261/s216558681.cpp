#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> moji(n);
  set<string> S;
  for (int i = 0; i < n; i++) {
    cin >> moji.at(i);
    S.insert(moji.at(i));
  }
  
  if (S.size() != n) {
    cout << "No" << endl;
  }
  else {
    for (int i = 0; i < n - 1; i++) {
      if (moji.at(i).at(moji.at(i).size() - 1) != moji.at(i + 1).at(0)) {
        cout << "No" << endl;
        break;
      }
      else {
        if (i == n - 2) {
          cout << "Yes" << endl;
        }
      }
    }
  }
}
