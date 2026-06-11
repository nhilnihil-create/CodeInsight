#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;

int main(){
  int64_t n,k;
  cin >> n >> k;
  vector<int64_t> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<int64_t> ruiseki(1);
  rep(i,n){
    ruiseki.push_back(ruiseki.back()+a[i]);
  }
  vector<int64_t> cand;
  for(int64_t i=0;i < n+1;i++){
    for(int64_t j=i+1;j < n+1;j++){
      cand.push_back(ruiseki[j]-ruiseki[i]);
    }
  }
  /*rep(i,cand.size()){
    cout << cand[i] << ",";
  }*/
  int64_t sieve = 1;
  sieve = sieve << 60;
  vector<int64_t> goods = cand;
  while(sieve > 0){
    vector<int64_t> sieved;
    rep(i,goods.size()){
      if(goods[i] & sieve){
        sieved.push_back(goods[i]);
      }
    }
    if(sieved.size() >= k){
      goods.clear();
      goods = sieved;
    }
    sieve = sieve >> 1;
  }
  int64_t res = 0;
  rep(i,k){
    if(i == 0){
      res = goods[0];
    }else{
      res = res & goods[i];
    }
  }
  cout << res << endl; 
      
}
  
  