#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<string> vecb(N);
   for (int i = 0; i < N; i++) {
     cin >> vecb.at(i);
   }
  int M;
  cin >> M;
  vector<string> vecr(M);
   for (int i = 0; i < M; i++) {
     cin >> vecr.at(i);
   }
  int x = 0;
   for (int i = 0; i < N; i++) {
     int a = 0;
     for (int j = 0; j < N; j++) {
       if(vecb.at(j) == vecb.at(i))
         a ++;
     }
        for (int k = 0; k < M; k++) {
          if(vecr.at(k) == vecb.at(i))
            a--;
        }
     if (a > x)
       x = a;
   }
  cout << x << endl;
}