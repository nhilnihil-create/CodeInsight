#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 1100
#define MAXW 22000

ll dp[MAXN][MAXW];

int main(){
  int n;cin>>n;
  vector<int>w(n), s(n), v(n);
  rep(i, n){
    cin>>w[i]>>s[i]>>v[i];
  }

  vector<pi>ss;
  rep(i, n)ss.push_back({s[i]+w[i], i});
  sort(ss.begin(), ss.end());

  rep(i, n){
    int ci=ss[i].second;
    ll cw=w[ci], cs=s[ci], cv=v[ci];
    dp[i+1][cw] = cv;
    rep1(j, MAXW){
      dp[i+1][j] = max<ll>(dp[i+1][j], dp[i][j]);
      if(j-cw>=0 && j-cw<=cs)dp[i+1][j] = max<ll>(dp[i+1][j], dp[i][j-cw]+cv);
    }
  }

  ll result = 0;
  rep(i, MAXW)result = max<ll>(result, dp[n][i]);

  cout<<result<<endl;
    

  return 0;
}
