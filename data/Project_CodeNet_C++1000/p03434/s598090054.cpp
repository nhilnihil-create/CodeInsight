#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N), card(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
   for (int i = 0; i < N; i++) {
     int a = vec.at(i);
       for (int i = 0; i < N; i++) {
         if (vec.at(i) == a)
           card.at(i) ++;
       }
   }
  int x = 0;
   for (int i = 0; i < N; i++) {
     int b = 0;
      for (int i = 0; i < N; i++) {
        if(vec.at(i) > b && card.at(i) >= 1)
          b = vec.at(i);
      }
     for (int i = 0; i < N; i++) {
       if (vec.at(i) == b)
         card.at(i) --;
     }
     if (i % 2 == 0)
       x += b;
     else
       x -= b;
   }
  cout << x << endl;
}