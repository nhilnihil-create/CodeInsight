#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
  cin >> n;
  int ans = 0;
  while(true){
    if(n-3<0) break;
    else if(n-3>=0){
      n-=3;
      ++ans;
    }
  }
  cout << ans << endl;
}
