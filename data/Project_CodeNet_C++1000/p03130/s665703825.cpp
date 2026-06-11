#include <bits/stdc++.h>
using namespace std;
int main () {
  int a[3],  b[3], sum=0;
  for(int i = 0; i < 3; i++) {
    cin >> a[i] >> b[i];
    sum += (a[i] + b[i]);
  }
  if(sum == 15) cout << "YES";
  else cout << "NO";
}
