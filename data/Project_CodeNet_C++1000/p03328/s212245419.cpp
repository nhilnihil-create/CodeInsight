#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
 
  int sum = 0;
  for (int i = 0; i < b-a; i++) {
    sum += i+1;
  }
  
  cout << sum - b << endl;
}

  