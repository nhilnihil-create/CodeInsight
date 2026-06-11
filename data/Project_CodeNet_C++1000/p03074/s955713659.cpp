#include <bits/stdc++.h>
#define int long long 
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 998244353;

int ctoi(char c) {
  if( c >= '0' && c <= '9' ) return c-'0';
  else return -1;
}

signed main() {
  int N, K;
  cin >> N >> K;
  
  string S;
  cin >> S;
  
  vector<int> num;
  int start = ctoi(S.at(0));
  int cnt = 1;
  bool fg;
  if( S.at(0) == '1' ) fg = 1;
  else fg = 0;
  for( int i = 1; i < S.size(); i++ ){
    if( S.at(i) == S.at(i-1) ) cnt++;
    else{
      num.push_back(cnt);
      cnt = 1;
    }
  }
  num.push_back(cnt);
  
  int k = 0;
  int ans = 0; 
  int now = 0;
  for( int i = 0; i < num.size(); i++ ){
    now += num.at(i);
    if( start == 0 && i%2 == 0 ) k++;
    else if( start == 1 && i%2 == 1 ) k++;
    if( k > K ){
      now -= num.at(i-2*K);
      if( i-2*K-1 >= 0 ) now -= num.at(i-2*K-1);
      k--;
    }
    ans = max(ans, now);
  }
  cout << ans << endl;
}
