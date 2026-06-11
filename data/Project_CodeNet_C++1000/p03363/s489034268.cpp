#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main() {
  ll n;cin >> n;
  vector<ll> a(n),s(n+1,0);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) s[i+1]=s[i]+a[i];
  map<ll,ll> m;
  ll ans=0;
  for(int i=0;i<=n;i++){
    ans+=m[s[i]]++;
  }
  cout << ans << endl;
}
