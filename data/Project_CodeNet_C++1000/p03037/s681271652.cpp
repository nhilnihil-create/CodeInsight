#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> L(M);
  vector<int> R(M);
  int maxL =0;
  int minR =100000;
  for (int i =0; i<M; i++) {
    cin >> L.at(i);
    cin >> R.at(i);
    maxL = max(L.at(i),maxL);
    minR = min(R.at(i),minR);
  }
  
  if (minR - maxL >= 0) {
    cout << minR - maxL + 1 << endl;
  } else {
    cout << 0 << endl;
  }
}