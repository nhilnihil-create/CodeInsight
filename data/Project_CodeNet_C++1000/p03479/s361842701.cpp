#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x, y; cin >> x >> y;
  int cnt  = 0;
  while(y >= x){
    cnt++;
    x *= 2;
  }
  cout << cnt << endl;
}
    
    