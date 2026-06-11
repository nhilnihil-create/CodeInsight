#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  long long l0=2, l1=1;
  long long li;
  if( n ==1) cout << l1 << endl;
  else {
  for(int i = 2;i<=n;i++){
    li = l1 + l0;
    l0 = l1;
    l1 = li;
  }
  cout << li << endl;
  }
}