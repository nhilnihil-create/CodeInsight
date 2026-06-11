#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  vector<double> t(N,0);
   for (int i = 0; i < N; i++) {
     t.at(i) = T - vec.at(i) * 0.006;
   }
  double a = A - t.at(0);
  int x = 0;
  if (a < 0)
    a = a * ( -1);
   for (int i = 0; i < N; i++) {
     double b = A - t.at(i);
     if (b < 0)
       b = b * (-1);
     if (b <= a) {
       a = b;
       x = i + 1;
     }
   }
  cout << x << endl;
}