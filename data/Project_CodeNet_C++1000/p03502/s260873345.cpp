#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,X,H;
  cin >> X;
  H = 0, N = X;
  while (0<N) H += N%10,N /= 10;
  if ( X%H == 0) cout << "Yes" <<endl;
  else cout << "No" << endl;
}