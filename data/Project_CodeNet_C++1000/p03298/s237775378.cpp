#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N; cin >> N;
  string s; cin >> s;
  string sf = s.substr(0, N);
  string ss = s.substr(N, N);
  reverse(ss.begin(), ss.end());
  
  ll ans = 0;
  for(int i = 0; i < (1<<N); i++){
    string red = "", blue = "";
    for(int j = 0; j < N; j++){
      if((i>>j)&1) red += sf[j];
      else blue += sf[j];
    }
    
    int R = red.size(), B = blue.size();
    vector<vector<ll> > dp(R+1, vector<ll>(B+1, 0LL) );
    
    dp[0][0] = 1LL;
    for(int r = 0; r < R; r++){
      if(red[r] == ss[r]) dp[r+1][0] = dp[r][0];
    }
    for(int b = 0; b < B; b++){
      if(blue[b] == ss[b]) dp[0][b+1] = dp[0][b];
    }
    
    for(int r = 0; r < R; r++){
      for(int b = 0; b < B; b++){
        if(ss[r+b+1] == red[r]) dp[r+1][b+1] += dp[r][b+1];
        if(ss[r+b+1] == blue[b]) dp[r+1][b+1] += dp[r+1][b];
      }
    }
    ans += dp[R][B];
  }
  
  cout << ans << endl;
}