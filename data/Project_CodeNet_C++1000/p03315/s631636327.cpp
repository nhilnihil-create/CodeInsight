#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  string S; cin >> S;
  int ans = 0;
  rep(i, 4){
    if(S.at(i) == '+'){
      ans++;
    } else if(S.at(i) == '-'){
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}