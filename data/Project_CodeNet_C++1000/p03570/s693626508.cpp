#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<char,int>;
const int inf = numeric_limits< int >::max()/3;

int bit[200010];
int dp[100000000];

int main(void){
  string s;
  cin >> s;
  int n = (int)s.size();
  fill(bit,bit+200010,0);
  fill(dp,dp+100000000,inf);
  bit[0] = 0;
  for(int i = 0;i < n;++i){
    bit[i+1] = bit[i] ^ (1 << s[i]-'a');
  }
  dp[0] = 0;
  for(int i = 1;i <= n;++i){
    int calc = dp[bit[i]] + 1;
    for(int j = 0;j < 26;++j){
      int mask = 1 << j;
      calc = min(calc,dp[bit[i]^mask]+1);
    }
    dp[bit[i]] = min(dp[bit[i]],calc);
    if(i == n)cout << calc << endl;
  }
  return 0;
}
