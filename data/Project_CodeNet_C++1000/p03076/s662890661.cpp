#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  vector<int> ABCDE(5); rep(i, 5) cin >> ABCDE.at(i);
  int min1 = 10;
  int num;
  rep(i, 5){
    if(min1 > ABCDE.at(i)%10 && ABCDE.at(i)%10 != 0){
      min1 = ABCDE.at(i)%10;
      num = i;
    }
  }
  int ans = 0;
  rep(i, 5){
    if(i != num){
      ans += (((ABCDE.at(i)-1)/10)+1)*10;
    }
  }
  ans += ABCDE.at(num);
  cout << ans << endl;
  return 0;
}
