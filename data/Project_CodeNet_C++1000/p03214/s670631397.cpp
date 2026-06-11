#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> P;

int main(void) {
  int N;
  cin >> N;
  vector<P> a(N);
  double ave = 0;
  for (int i = 0; i < N; i++) {
    double tmp;
    cin >> tmp;
    a[i] = P(tmp, i);
    ave += tmp;
  }
  ave /= N;
  for (int i = 0; i < N; i++) {
    a[i] = P(abs(a[i].first - ave), a[i].second);
  }
  sort(a.begin(), a.end());
  cout << a[0].second << endl;
  return 0;
}