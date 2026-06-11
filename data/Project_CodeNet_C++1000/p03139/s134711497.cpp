#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  cout << min(a,b) << ' ';
  if(a+b>n) cout << a+b-n << endl;
  else cout << 0 << endl;
}