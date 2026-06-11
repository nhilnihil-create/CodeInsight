#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, A;
  int n;
  
  cin >> N >> A;
  
  n = N / 500;
  if(N - n * 500 <= A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}