#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec(5);
  int k;
  cin >> vec[0] >> vec[1] >> vec[2] >> vec[3] >> vec[4] >> k;
  bool flg = true;
  sort(vec.begin(), vec.end());

  if(vec[4]-vec[0] > k) {
    flg = false;
  }
  flg == true ? cout << "Yay!" << endl : cout << ":(" << endl;
}