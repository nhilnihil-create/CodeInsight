#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int length1 = S.size();
  vector<char> kaibun;
  vector<int> position;
  int tmp = 0;
  for (int i = 0; i < length1; i++) {
    if (S[i] != 'x') {
      kaibun.push_back(S[i]);
      position.push_back(tmp);
      tmp = 0;
    }
    else tmp++;
  }
  position.push_back(tmp);
  int length2 = kaibun.size();
  bool can = true;
  for (int i = 0; i < length2/2; i++) {
    if (kaibun[i] != kaibun[length2-1-i]) {
      can = false;
      break;
    }
  }
  int res = -1;
  int length3 = position.size();
  if (can) {
    res++;
    for (int i = 0; i < length3/2; i++) {
      res += abs(position[i] - position[length3-1-i]);
    }
  }
  cout << res << endl;
}
