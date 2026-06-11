#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string ans;
  while(n != 0){
    if(n%2 != 0){
      ans = '1' + ans;
      --n;
    }else{
      ans = '0' + ans;
    }
    n /= (-2);
  }
  if(ans.size() == 0) cout << 0 << endl;
  else cout << ans << endl;
}