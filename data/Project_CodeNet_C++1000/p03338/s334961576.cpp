#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep2(i, 1, n-1){
    string fr = s.substr(0, i);
    string re = s.substr(i);
    map<char, int> mp;
    for(char c : fr) mp[c] = 1;
    int add = 0;
    for(char c : re){
      if(mp[c] == 1){
        add++;
        mp[c]--;
      }
    }
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}