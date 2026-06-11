#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n){
    int a;
    cin >> a;
    mp[a]++;
  }
  int ans = 0;
  rrepit(itr, mp){
    int i = itr->first;
    int j = (1 << ((int)log2(i) + 1)) - i;
    int add = 0;
    if(i == j){
      add = itr->second/2;
      itr->second -= add*2;
    }else{
      add = min(itr->second, mp[j]);
      itr->second -= add;
      mp[j] -= add;
    }
    ans += add;
  }
  cout << ans << endl;
  return 0;
}