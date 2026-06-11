#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool comp(P p1,P p2){
  return (p1.first == p2.first && p1.second > p2.second) || p1.first < p2.first;
}
bool comp1(P p1,P p2){
  return p1.second > p2.second;
}
int main(){
  ll n,h;
  cin >> n >> h;
  ll i;
  vector<P> p(n);
  for(i=0;i<n;i++){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(),p.end(),comp);
  ll a=p[n-1].first,b=p[n-1].second;
  ll ans=0,sum=0,res=0;
  sort(p.begin(),p.end(),comp1);
  for(i=0;i<n;i++){
    if(sum>=h){
      break;
    }
    if(a>p[i].second){
      break;
    }
    if(res==0 && p[i].first==a && p[i].second==b){
      res=1;
      continue;
    }
    ans++,sum+=p[i].second;
  }
  if(sum>=h){
    cout << ans << endl;
    return 0;
  }
  sum+=b,ans++;
  if(sum>=h){
    cout << ans << endl;
    return 0;
  }
  ans+=(h-sum-1)/a+1;
  cout << ans << endl;
}