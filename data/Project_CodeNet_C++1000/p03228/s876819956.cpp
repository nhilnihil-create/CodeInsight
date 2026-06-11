#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a, b, k; cin >> a >> b >> k;
  for(int i = 0; i < k; i++){
    if(a&1) a--;
    b += a/2;
    a /= 2;
    swap(a, b);
  }
  if(k&1) swap(a, b);
  cout << a << " " << b << endl;
  return 0;
}