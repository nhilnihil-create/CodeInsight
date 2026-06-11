#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int imax = N/4;
  int jmax = N/7;
  string Ans = "No";
  for (int i= 0; i <= imax ; i++){
    for (int j = 0; j <= jmax; j++){
      if (i*4 + j*7 == N) Ans = "Yes";
    }
  }
  cout << Ans << endl;
} 
