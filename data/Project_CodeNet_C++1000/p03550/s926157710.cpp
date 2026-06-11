#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1001001001;



int main() {
  ll n,z,w;
  cin>>n>>z>>w;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  ll ans;

  if (n==1){
    ans=abs(w-a[0]);
    cout<<ans;
    return 0;
  }
  else{
  ll last=a[n-1];
  ll last2=a[n-2];

  ll ans1=abs(w-last);
  ll ans2=abs(last-last2);
  ans=max(ans1,ans2);
  cout<<ans;
}
}
