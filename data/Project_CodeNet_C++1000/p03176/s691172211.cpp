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

#define MAXN 200001

ll dp[MAXN+1];
int h[MAXN+1];
int a[MAXN+1];
ll bit[MAXN+1];
pi flowers[MAXN+1];

void set_val(int idx, ll val){
  idx++;
  while(idx<MAXN+1){
    bit[idx] = max(bit[idx], val);
    idx += idx & -idx;
  }
}

ll max_val(int idx){
  ll res=0;
  idx++;
  while(idx){
    res = max(res, bit[idx]);
    idx -= idx & -idx;
  }
  return res;
}

int main(){
  int n;cin>>n;
  rep(i, n)cin>>h[i];
  rep(i, n)cin>>a[i];
  rep(i, n){
    flowers[i].first = h[i];
    flowers[i].second = i;
  }
  sort(flowers, flowers+n);

  ll ans=0;
  rep(i, n){
//cout<<flowers[i].first<<' '<<flowers[i].second<<endl;
    int ci = flowers[i].second;
    dp[ci] = max_val(ci-1)+a[ci];
    set_val(ci, dp[ci]);
    ans = max<ll>(ans, dp[ci]);
//cout<<ans<<endl;

  }

  cout<<ans<<endl;

  return 0;
}
