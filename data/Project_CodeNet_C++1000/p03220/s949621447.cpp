#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  double d = 100000;
  int id = 0;
  vector<int> H(N);
  
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
    double h = T - H.at(i) * 0.006;
    double ad = abs(A - h);
    if (ad <= d) {
      d = ad;
      id = i + 1;
    }
  }
  
  cout << id << endl;
}
