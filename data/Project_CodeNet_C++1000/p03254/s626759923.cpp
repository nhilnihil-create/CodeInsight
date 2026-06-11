#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x;
  cin >> N >> x;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  sort(vec.begin(), vec.end());
  int a = 0, b = x;  
   for (int i = 0; i < N; i++) {
     if (vec.at(i) < b) {
       a ++;
       b -= vec.at(i);
     }
     else if (vec.at(i) == b) {
       a ++;
       b -= vec.at(i);
       break;
     }
     else
       break;
   }
  if (a == N && b > 0)
    a --;
  cout << a << endl;
}