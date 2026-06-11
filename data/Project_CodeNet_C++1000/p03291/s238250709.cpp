#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  string s;
  cin >> s;
  vector<vector<long>> dp(3,vector<long>(s.size()+1,0));
  long state = 1;
  rep(i,s.size()){
    if(s.at(i) == 'A'){
      dp.at(0).at(i+1) = (dp.at(0).at(i) + state)%MOD;
      dp.at(1).at(i+1) = dp.at(1).at(i);
      dp.at(2).at(i+1) = dp.at(2).at(i);
    }
    if(s.at(i) == 'B'){
      dp.at(0).at(i+1) = dp.at(0).at(i);
      dp.at(1).at(i+1) = (dp.at(1).at(i) + dp.at(0).at(i))%MOD;
      dp.at(2).at(i+1) = dp.at(2).at(i);
    }
    if(s.at(i) == 'C'){
      dp.at(0).at(i+1) = dp.at(0).at(i);
      dp.at(1).at(i+1) = dp.at(1).at(i);
      dp.at(2).at(i+1) = (dp.at(2).at(i) + dp.at(1).at(i))%MOD;
    }
    if(s.at(i) == '?'){
      dp.at(2).at(i+1) = (3*dp.at(2).at(i) + dp.at(1).at(i))%MOD;
      dp.at(1).at(i+1) = (3*dp.at(1).at(i) + dp.at(0).at(i))%MOD;
      dp.at(0).at(i+1) = (3*dp.at(0).at(i) + state)%MOD;
      state *= 3;
      state %= MOD;
    }
  }
  /*rep(i,s.size()+1){
    rep(j,3) cout << dp[j][i] << " ";
    cout << endl;
  }*/
  cout << dp.at(2).at(s.size())%MOD << endl;
}
