#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


bool roop(vector<int> vec, int k) {
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (k < vec.at(j) - vec.at(i)) return false;
    }
  }
  return true;
}

int main() {
  int k;
  vector<int> vec(5);
  for (int i = 0; i < 5; i++) {
    cin >> vec.at(i);
  }
  cin >> k;
  if (roop(vec, k)) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}
