#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  double d;
  cin >> N >> A;
  d = N / 500;
  if ( (N - d * 500) <= A)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}