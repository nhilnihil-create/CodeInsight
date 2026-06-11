#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k; string s;
  cin >> n >> k >> s;

  vector<int> v;
  char c = '1'; int cnt = 0;
  rep(i,n){
    if(c!=s[i]){
      v.push_back(cnt);
      c = s[i];
      cnt = 0;
    }
    cnt++;
  } 
  v.push_back(cnt);
  if(c=='0') v.push_back(0);

  int ans = 0;
  if(v.size()/2<=k){
    ans = n;
  }else{
    vector<int> s(v.size()+1);
    rep(i,v.size()) s[i+1] = s[i] + v[i];
    for(int i = 0; i+2*k<v.size(); i+=2 ){
      ans = max(ans,s[i+2*k+1]-s[i]);
    }
  }
  cout << ans << endl;
}