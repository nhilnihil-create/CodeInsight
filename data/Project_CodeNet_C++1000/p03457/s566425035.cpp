#include <bits/stdc++.h>
using namespace std;
 
int steps(int x1, int y1, int x2, int y2) {
  return max(x1-x2,x2-x1) + max(y1-y2,y2-y1);
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> p(N, vector<int>(3));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> p.at(i).at(j);
    }
  }
  bool b = 1;
  int c = steps(0,0,p.at(0).at(1),p.at(0).at(2)) - p.at(0).at(0);
    if (c > 0 || (c % 2) == -1) {
      b = 0;
      goto FF;
    }
  for (int i = 1; i < N; i++) {
    int d = steps(p.at(i).at(1), p.at(i).at(2), p.at(i-1).at(1), p.at(i-1).at(2)) - (p.at(i).at(0) - p.at(i-1).at(0));
    if (d > 0 || (d % 2) == -1) {
      b = 0;
      break;
    }
  }
  FF:
  if (b == 1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}