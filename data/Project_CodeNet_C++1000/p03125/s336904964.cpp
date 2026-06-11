#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int ans = 0;
  if(m%n==0) ans = m + n;
  else ans = m-n;
  cout << ans << endl;
}