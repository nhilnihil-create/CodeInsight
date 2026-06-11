#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i,n)cin >> A.at(i);
  vector<ll> D(n);
  rep(i,n){
    D.at(i) = A.at(i)-(i+1);
  }
  sort(D.begin(),D.end());
  ll median;
  if(n%2==0)median=(D.at(n/2)+D.at(n/2-1))/2;
  else median=D.at(n/2);
  ll ans = 0;
  rep(i,n){
    ans+=abs(D.at(i)-median);
  }
  cout<<ans<<endl;
  return 0;
}