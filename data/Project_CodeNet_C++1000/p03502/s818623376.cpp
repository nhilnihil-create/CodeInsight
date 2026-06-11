#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int sum = 0;
  int work = n;
  
  while (work > 0) {
  	sum += (work % 10);
    work /= 10;
  }
  
  if(n % sum  == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl; 
  }
}
