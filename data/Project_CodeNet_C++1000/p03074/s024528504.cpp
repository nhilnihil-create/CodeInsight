#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,k;
  string s;
  cin >> n >> k >> s;
  vector<P>data(0);
  char st = s[0];
  int cnt = 0;
  rep(i,0,n){
    if(st != s[i]){
      data.push_back(P(cnt,st-'0'));
      st = s[i];
      cnt = 1;
    }
    else cnt++;
  }
  if(cnt != 0) data.push_back(P(cnt,st-'0'));
  
  vector<P>sum(data.size());
  sum[0].first = data[0].first;
  sum[0].second = data[0].second;
  rep(i,1,data.size()){
    sum[i].first = sum[i-1].first+data[i].first;
    sum[i].second = data[i].second;
  }
  
  int ans = 0;
  rep(i,0,sum.size()){
    int tmp,b,f;
    if(sum[i].second == 0){
      if(i+2*k-1 < sum.size()) b = sum[i+2*k-1].first;
      else b = sum[sum.size()-1].first;
      if(i-2 >= 0) f = sum[i-2].first;
      else f = 0;
    }
    else{
      if(i+2*k < sum.size()) b = sum[i+2*k].first;
      else b = sum[sum.size()-1].first;
      if(i-1 >= 0) f = sum[i-1].first;
      else f = 0;
    }
    tmp = b-f;
    ans = max(ans,tmp);
  }
  cout << ans << endl;
}