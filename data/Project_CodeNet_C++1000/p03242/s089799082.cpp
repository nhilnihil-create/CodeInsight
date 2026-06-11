#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  if(n/100 == 1) cout << 9;
  else cout <<1;
  
  if((n/10)%10 == 1) cout << 9;
  else cout << 1;
  
  if(n%10 == 1) cout << 9 << endl;
  else cout << 1 << endl;
  
}