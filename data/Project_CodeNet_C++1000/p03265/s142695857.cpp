#include <bits/stdc++.h>
using namespace std;
#define rep(i, n); for (int i = 0; i < (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << x2+y1-y2 << " " << y2-x1+x2 << " " << x1+y1-y2 << " " << y1-x1+x2 << endl;
}