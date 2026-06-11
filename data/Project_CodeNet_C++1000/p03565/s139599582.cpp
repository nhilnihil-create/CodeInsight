#include <bits/stdc++.h>
using namespace std;

bool finder(int now_place, string &S, string &T) {
  int tmp = 0;
  int S_size = S.size();
  for(int i = now_place; i < S_size; i++) {
    if(S.at(i)==T.at(tmp) || S.at(i) == '?') {
      tmp++;
      if (tmp >= T.size()) {
        return true;
      }
    } else {
      return false;
    }
  }
  return false;
}

int main() {
  string S, T, ans;
  cin >> S; cin >> T;
  int S_size = S.size(), T_size = T.size();
  vector<int> checker(S_size, 0);

  int key = -1;

  for (int i = 0; i < S_size; i++){
    if (S.at(i) == '?') {
      checker.at(i) = 1;
    }
    if(finder(i, S, T)) key = i;
  }

  if (key == -1) {
    cout << "UNRESTORABLE";
  } else {
    for(int i = 0; i < S_size; i++){
      if(checker.at(i) == 1) {
        if(i - key < 0 || i - key >= T_size) {
          S.at(i) = 'a';
        } else {
          S.at(i) = T.at(i - key);
        }
      }
    }
  cout << S << endl;
  }
}