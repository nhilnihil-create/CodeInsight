#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int M, L;
  M = N  / 10;
  L = N % 1000;
  if (N % 1111 == 0) {cout << "Yes" << endl;}
  else if (M % 111 == 0) {cout << "Yes" << endl;}
  else if (L % 111 == 0) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}