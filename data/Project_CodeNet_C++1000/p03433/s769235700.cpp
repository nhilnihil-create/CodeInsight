#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A ;

  int c = N % 500;
  
  if (A >= c) cout << "Yes" << endl;
  else cout << "No" << endl;
}