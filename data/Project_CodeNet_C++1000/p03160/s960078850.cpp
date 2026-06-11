#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;

const ll INF=1LL << 60;

template<class T> inline bool chmin(T& a, T b){
  if(a>b){
    a=b;
    return true;
  }
  else return false;
}

template<class T> inline bool chmax(T& a, T b){
  if(a<b){
    a=b;
    return true;
  }
  else return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  ll h[100010], dp[100010];
  rep(i, n)cin >> h[i];
  rep(i, n)dp[i]=INF;
  dp[0]=0;

  rep(i, n){
    chmin(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
    if(i>1)chmin(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
  }

  cout << dp[n-1] << endl;

  return 0;
}
