#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  double sum;
  
  for (int i = 0; i < N; i++) {
    double x;
    string u;
    cin >> x >> u;
    
    if (u == "JPY") {
      sum += x;
    }
    else {
      sum += x * 380000.0;
    }
  }
  cout << sum << endl;
}