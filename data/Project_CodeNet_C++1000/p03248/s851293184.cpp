#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

void fail(){
  cout << -1 << endl;
  exit(0);
}

signed main(){

  string s; cin >> s;

  int n = s.size();
  if(s[0] != '1' || s[n-1] != '0') fail();
  for(int i = 1; i < n-1; i++){
    if(s[i] != s[n-1 - i-1]) fail();
  }

  queue<int> q;
  for(int i = 0; i < n; i++){
    if(s[i] == '1'){
      q.push(i + 1);
    }
  }
  q.push(n);
  //uの部分グラフがs[u]になればいい
  for(int i = 1; i < n; i++){
    if(i == q.front()){
      q.pop();
    }
    cout << i << " " << q.front() << endl;
  }

  return 0;
}
