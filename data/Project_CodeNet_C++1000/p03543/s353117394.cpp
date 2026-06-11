#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int N4 = N/1000;
  int N3 = (N-N4*1000)/100;
  int N2 = (N-N4*1000-N3*100)/10;
  int N1 = N-N4*1000-N3*100-N2*10;
  
  if (((N4 == N3) && (N3 == N2))
      || ((N3 == N2) && (N2 == N1))) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}