#include <bits/stdc++.h>
//#define int long long
#define N 200010
using namespace std;
const int INF = 1e9;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
string str;
int n;
int Bit[N];

void init(){for(int i=1;i<=n;i++) Bit[i] = Bit[i-1] ^ (1LL<<(str[i-1]-'a'));}


int solve(){
  vector<int> opt(N,INF);
  vector<int> dp(1<<26,INF);
  opt[0] = dp[0] = 0;

  for(int i=1;i<=n;i++) {
    int bit = Bit[i];
    opt[i] = dp[bit]+1;
    for(int j=0;j<26;j++) Min(opt[i],dp[bit^(1<<j)]+1);
    Min(dp[bit],opt[i]);
  }
  return opt[n];
}

signed main(){
  cin>>str;
  n = str.size();
  init();

  cout<<solve()<<endl;
  return 0;
}
