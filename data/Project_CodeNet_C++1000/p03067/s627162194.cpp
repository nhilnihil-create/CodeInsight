#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int mn = min(a, b);
  int mx = max(a, b);
  if(mn <= c && c <= mx) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}