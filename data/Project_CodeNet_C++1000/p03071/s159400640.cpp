#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int maxi=max(a,b);
  cout << max((maxi<<1)-1, a+b) << endl;
  return 0;
}