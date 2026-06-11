#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,d,x,A[200],B[200];
  cin >> n >> d >> x;
  for(int i = 0; i < n; i++) {
    cin >> A[i];
    B[i] = 1;
  }
  
  int sum = x;
  for(int i = 0; i < n; i++) {
    while(B[i] <= d) {
      B[i] += A[i];
      sum++;
    }
  }
  cout << sum << endl;
}