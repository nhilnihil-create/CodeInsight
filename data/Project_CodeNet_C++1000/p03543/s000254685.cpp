#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, s1, s2, s3, s4;
  cin >> N;
  if ((N / 10) % 111 == 0 | (N % 1000) % 111 == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }  
}