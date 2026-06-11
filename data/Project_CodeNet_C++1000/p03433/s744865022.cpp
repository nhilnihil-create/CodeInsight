#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A ;
  cin >> N >> A;
  int B = N - (N / 500 * 500) ;
  if (A >= B)
  cout << "Yes" << endl;
  else if (A < B)
  cout << "No"<< endl;
}