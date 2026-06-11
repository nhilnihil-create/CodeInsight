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
  string s;
  cin >> s;
  string nx;
  rep(i, s.size()){
    if(s.at(i) != 'x') nx.push_back(s.at(i));
  }
  string rnx = nx;
  reverse(rnx.begin(), rnx.end());
  if(rnx != nx){
    cout << -1 << endl;
    return 0;
  }
  vector<int> xx(nx.size()+1, 0);
  int index = 0;
  rep(i, nx.size()){
    if(s.at(index) ==  'x'){
      xx.at(i)++;
      i--;
    }
    index++;
  }
  xx.back() = s.size() - (index);
  // for(int i : xx){
  //   cerr << i << " ";
  // }
  // cerr << endl;
  int ans = 0;
  rep(i, xx.size()/2){
    ans += abs(xx.at(i)-xx.at(xx.size()-i-1));
  }
  cout << ans << endl;
  return 0;
}