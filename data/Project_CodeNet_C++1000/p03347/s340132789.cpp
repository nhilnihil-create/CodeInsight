#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

ll fanc(vector<int> &now){
  ll ret = now.front();
  ll sum = ret;
  int bf = now.front();
  rep2(k, 1, now.size()){
    // cerr << i << " " << ret << " " << sum << endl;
    if(bf == now.at(k)){
      ret += sum;
    }else{
      sum++;
      ret++;
    }
    bf = now.at(k);
  }
    // cerr << i << " " << ret << " " << sum << endl;
  return ret;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    int in;
    cin >> in;
    a.at(i) = in;
    bool flag = true;
    if(i == 0){
      if(in != 0) flag = false;
    }else{
      if(in - a.at(i-1) > 1) flag = false;
    }
    if(flag == false){
      cout << -1 << endl;
      return 0;
    }
  }
  int bf = 0;
  vector<int> now;
  now.push_back(a.front());
  ll ans = 0;
  rep2(i, 1, n){
    if(bf > a.at(i)){
      ll ret = fanc(now);
      if(ret == -1){
        cout << -1 << endl;
        return 0;
      }
      ans += ret;
      now.clear();
    }
    now.push_back(a.at(i));
    bf = a.at(i);
  }
  ll ret = fanc(now);
  if(ret == -1){
    cout << -1 << endl;
    return 0;
  }
  ans += ret;
  cout << ans << endl;
  return 0;
}