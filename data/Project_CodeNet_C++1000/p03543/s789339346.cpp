#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int N1 = (N/1)%10;
  int N2 = (N/10)%10;
  int N3 = (N/100)%10;
  int N4 = (N/1000)%10;
  
  if (N1 == N2 && N1 == N3) {
    cout << "Yes" << endl;
  }
  else if (N2 == N3 && N2 == N4) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}