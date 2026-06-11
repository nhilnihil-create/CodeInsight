#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string s;
  cin >> s;
  int flag1 = 0, id1 = 0, id2 = 0, flag4 = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'K' && s[i + 1] == 'I' && s[i + 2] == 'H') {
      if (s[i + 3] == 'B') {
        if (s[i + 4] == 'R') {
          flag1 = 1;
          id1 = i;
          id2 = i + 4;
        }
        else if (s[i + 5] == 'R') {
          flag1 = 1;
          id1 = i;
          id2 = i + 5;
        }
      }
      else if (s[i + 4] == 'B') {
        if (s[i + 5] ==  'R') {
          flag1 = 1;
          id1 = i;
          id2 = i + 5;
        }
        else if (s[i + 6] == 'R') {
          flag1 = 1;
          id1 = i;
          id2 = i + 6;
        }
      }
    }
    if (!(s[i] == 'A' || s[i] == 'K' || s[i] == 'I' || s[i] == 'H' || s[i] == 'B' || s[i] == 'R')) {
      flag4 = 0;
    }
  }
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A' && i < id1) {
      cnt1++;
    }
    if (s[i] == 'A' && i > id2) {
      cnt2++;
    }
  }
  int flag2 = 0;
  if (cnt1 <= 1 && cnt2 <= 1) {
    flag2 = 1;
  }
  string t = "KIHBR";
  int flag3 = 1;
  for (int i = 0; i < t.size(); i++) {
    int tmp = count(s.begin(), s.end(), t[i]);
    if (tmp > 1) {
      flag3 = 0;
    }
  }
  if (flag1 && flag2 && flag3 && flag4) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}