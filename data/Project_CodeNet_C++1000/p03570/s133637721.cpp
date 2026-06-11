#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 21;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const int INF = 1 << 30;

string s;
int dp[1 << 26];

int main(){
  cin >> s;
  ll bit = 0;
  fill(dp,dp+(1<<26),INF);
  dp[0] = 0;
  for(char c : s){
    bit ^= (1 << c-'a');
    int m = INF;
    for(ll i = 0;i < 26;i++){
      m = min(m,dp[(bit^(1 << i))]);
    }
    dp[bit] = min(dp[bit],m+1);
  }
  cout << max(1,dp[bit]) << endl;

}
