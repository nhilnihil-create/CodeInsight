#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N; 

// N%10 N%100/10 N%1000/100 N/1000
  if (N%10 == (N%100)/10 && (N%100)/10 == (N%1000)/100 && (N%1000)/100 == N/1000) {
  cout << "Yes" << endl;
  }
  else if (N%10 == (N%100)/10 && (N%100)/10 == (N%1000)/100) {
  cout << "Yes" << endl;
  }
  else if ((N%100)/10 == (N%1000)/100 && (N%1000)/100 == N/1000) {
  cout << "Yes" << endl;
  }
  else {
  cout << "No" << endl;
  }
}