#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int n;
  cin >> n;
  vector<int> cnt(13,0);
  rep(i,n){
    int x;cin >> x;
    cnt[x]++;
  }
  vector<int> all,one;
  all.push_back(0);
  rep(i,13){
    if((i == 0 && cnt[i] > 0) || cnt[i] > 2){
      cout << 0 << endl;
      return 0;
    }else if(cnt[i] == 2){
      all.push_back(i);
      all.push_back(24-i);
    }else if(cnt[i] == 1){
      one.push_back(i);
    }
  }
  int k = one.size();
  int res = 0,gg = 1 << 30;
  rep(i,all.size())for(int j = i+1;j < all.size();j++){
    gg = min(gg,min(abs(all[i]-all[j]),24-abs(all[i]-all[j])));
  }
  for(int bit = 0;bit < (1 << k);bit++){
    vector<int> use;
    rep(i,k)if(bit >> i & 1){
      use.push_back(one[i]);
    }else{
      use.push_back(24-one[i]);
    }
    int sa = gg;
    rep(i,k){
      for(int j = i+1;j < k;j++){
        sa = min(sa,min(24-abs(use[i]-use[j]),abs(use[i]-use[j])));
      }
    }
    rep(i,k)rep(j,all.size()){
      sa = min(sa,min(abs(use[i]-all[j]),24-abs(use[i]-all[j])));
    }
    res = max(res,sa);
  }
  cout << res << endl;
  



  return 0;
}