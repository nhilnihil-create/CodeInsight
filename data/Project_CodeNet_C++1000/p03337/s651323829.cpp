#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  if (b >= 0)
    cout << max(a+b, a*b) << endl;
  else
    cout << max(a-b, a*b) << endl;
}