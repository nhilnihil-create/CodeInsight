#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  int cnt = 0, memo = INF;
  ll ans = 0;
  for(int i=0; i<n; ++i){
    cin >> an[i];
    if(an[i] <0){
      ++cnt;
      ans += abs(an[i]);
    }else{
      ans += an[i];
    }
    memo = min(memo, abs(an[i]));
  }
  if(cnt%2 == 0){
    cout << ans << endl;
  }else{
    ans -= memo *2;
    cout << ans << endl;
  }
}