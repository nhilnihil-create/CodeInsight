#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n, a, b; cin >> n >> a >> b;

  if(a + b > n+1 || a * b < n){
    cout << -1 << endl;
    return 0;
  }
  vector<int> v;
  int kill = a * b - n;
  for(int i = 0; i < a*b; i+=b){
    for(int j = i+b; j > i; j--){
      v.push_back(j);
      if(kill >= b-1){
        kill -= b-1;
        break;
      }else if(kill > 0 && kill < b-1){
        j -= kill;
        kill = 0;
      }
    }
  }

  map<int, int> mp;
  int num = v.size();
  for(int i = 0; i < v.size(); i++){
    mp[v[i]] = -1;
  }
  for(auto p = mp.rbegin(); p != mp.rend(); p++){
    p->second = num--;
  }
  for(int i = 0; i < v.size(); i++){
    cout << mp[v[i]] << " ";
  }
  cout << endl;

  return 0;
}
