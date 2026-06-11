#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  string s;
  cin >> s;

  int l = 0;
  int r = s.size() - 1;
  int ans = 0;

  while(r > l){
    if(s[l] == s[r]){
      r --;
      l ++;
    }else{
      if(s[l] == 'x'){
        l ++; ans ++;
      }else if (s[r] == 'x'){
        r --; ans ++;
      }else{
        ans = -1; break;
      }
    }
  }

  cout << ans << endl;


  return 0;
}