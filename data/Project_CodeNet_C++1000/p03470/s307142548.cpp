#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int x = 0;
   for (int i = 0; i < N; i++) {
     x ++;
     if (i > 0 && vec.at(i) == vec.at(i-1))
       x--;
   }
  cout << x << endl;
}