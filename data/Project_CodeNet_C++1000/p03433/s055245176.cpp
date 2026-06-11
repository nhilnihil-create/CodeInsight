#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int A;
  int B;
  
  cin >> N;
  cin >> A;
  B = N % 500;
  if (A < B)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
