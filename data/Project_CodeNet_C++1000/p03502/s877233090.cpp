#include <bits/stdc++.h>
using namespace std;

int main(){
  int a = 0;
  cin >> a;
  int n = a;
  int sum = 0;
  for (int i = 10;i<=n;i *= 10){
    sum += (a % 10);
    a /= 10;
  }
  sum += a;
  if ( (n % sum) == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
