#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  int odd = (N+1)/2;
  int even = N/2;
  
  cout << odd * even << endl;
}