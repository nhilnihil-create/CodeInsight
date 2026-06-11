#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  int n,i;
  cin >> n;
  vector<P> x(n);
  for(i=0;i<n;i++){
    cin >> x[i].first >> x[i].second;
  }
  ll ma=0;
  for(i=0;i<n;i++){
    ma=max(ma,x[i].second);
  }
  ll sum=0;
  for(i=0;i<n;i++){
    sum+=ma-x[i].second;
  }
  for(i=0;i<n;i++){
    x[i].first+=sum-(ma-x[i].second);
  }
  sort(x.begin(),x.end(),greater<P>());
  ll ans1=0,ans2=0;
  for(i=0;i<n;i=i+2){
    ans1+=x[i].first-sum+(ma-x[i].second);
  }
  for(i=1;i<n;i=i+2){
    ans2+=x[i].second;
  }
  cout << ans1-ans2 << endl;
}