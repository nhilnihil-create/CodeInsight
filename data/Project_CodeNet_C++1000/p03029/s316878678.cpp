#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, p;
  cin >> a >> p;
  
  int k = 3*a + p;
  if (k%2 == 0)
    cout << k/2 << endl;
  else
    cout << (k-1)/2 << endl;
}