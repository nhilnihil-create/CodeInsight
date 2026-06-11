#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int c = 0, d = 0;
   for (int i = 0; i < N; i++) {
     if (c > 0 && S.at(i) != 'A' && S.at(i) != 'C' &&
         S.at(i) != 'G' && S.at(i) != 'T')
       d = 0;
     else if (S.at(i) == 'A' || S.at(i) == 'C' ||
         S.at(i) == 'G' || S.at(i) == 'T') {
       d ++;
       if (d >= c)
         c = d;
     }     
   }
  cout << c << endl;
}