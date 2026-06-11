#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  for(int i=2; i<=n; ++i) for(int j:prime){
    if(i%j == 0){
      int x = i;
      while(x%j == 0){
        x /= j;
        ++mp[j];
      }
    }
  }
  int cnt75 = 0, cnt25 = 0, cnt15 = 0, cnt5 = 0, cnt3 = 0;
  for(auto p:mp){
    if(p.second >= 74) ++cnt75;
    if(p.second >= 24) ++cnt25;
    if(p.second >= 14) ++cnt15;
    if(p.second >= 4) ++cnt5;
    if(p.second >= 2) ++cnt3;
  }
  int ans = cnt5*(cnt5-1)*(cnt3-2) /2;
  ans += cnt75;
  ans += cnt25 *(cnt3-1);
  ans += cnt15 *(cnt5-1);
  cout << ans << endl;
}