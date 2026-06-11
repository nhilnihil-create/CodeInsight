#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

ll inf=1e15;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m);
  for(ll i=0;i<m;i++) {
    cin >> a[i];
  }
  sort(a.rbegin(),a.rend());
  vector<ll> num={2,5,5,4,5,6,3,7,6};
  vector<ll> dp(n+1,-inf);
  dp[0]=0;
  for(ll i=1;i<=n;i++) {
    for(ll j=0;j<m;j++) {
      if(i-num[a[j]-1]>-1&&dp[i-num[a[j]-1]]!=-inf) {
        dp[i]=max(dp[i],dp[i-num[a[j]-1]]+1);
      }
    }
  }
  vector<ll> ans(dp[n]);
  ll temp=n;
  for(ll i=0;i<ans.size();i++) {
    for(ll j=0;j<m;j++) {
      if(temp-num[a[j]-1]>-1&&dp[temp-num[a[j]-1]]+1==dp[temp]) {
        ans[i]=a[j];
        temp=temp-num[a[j]-1];
        break;
      }
    }
  }
  for(ll i=0;i<ans.size();i++) {
    cout << ans[i];
  }
  cout << endl;
}