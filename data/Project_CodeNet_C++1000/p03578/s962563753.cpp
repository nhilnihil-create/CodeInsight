#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> D;
  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    if (D.count(d)) D.at(d)++;
    else D[d] = 1;
  }
  int M;
  cin >> M;
  string ans = "YES";
  for (int i = 0; i < M; i++) {
    int t;
    cin >> t;
    if (D.count(t)) {
      D.at(t) -= 1;
      if (D.at(t) == 0) D.erase(t);
    }
    else {
      ans = "NO";
      break;
    }
  }
  cout << ans << endl;
}