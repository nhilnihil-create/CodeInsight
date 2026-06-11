#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x = 1, y = 0, z;
  
  for(int i=0; ; i++) {
    x *= 10; 
    y += (N%x-N%(x/10))/(x/10);
    if(N < x)
     break;
}
  
  if(N%y == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}