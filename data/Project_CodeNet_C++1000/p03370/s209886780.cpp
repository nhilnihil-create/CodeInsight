#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  int a = 0;
   for (int i = 0; i < N; i++) {
     a += vec.at(i);
   }
  int b = vec.at(0);
   for (int i = 0; i < N; i++) {
     if (vec.at(i) < b)
       b = vec.at(i);
   }
  cout << N + (X - a) / b << endl;
}