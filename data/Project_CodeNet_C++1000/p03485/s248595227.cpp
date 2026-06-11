#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b;
  
  cin >> a >> b;
  
  double avg = double(a+b)/2;
  
  avg = avg + 0.5;
  
  cout << int(avg);
}