#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  vector<ll> sum_a(n+1);
  sum_a[0]=0;
  map<ll,ll> mp;
  mp[0]=1;
  rep(i,n){
    int A;
    cin>>A;
    sum_a[i+1]=sum_a[i]+A;
    mp[sum_a[i+1]]++;
  }
  ll ans=0;
  for(auto x : mp){
    ans+=x.second*(x.second-1)/2;
  }
  cout<<ans<<endl;
}