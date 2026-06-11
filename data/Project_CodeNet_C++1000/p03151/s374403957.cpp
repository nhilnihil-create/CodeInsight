#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),b(n);
  ll suma=0,sumb=0;
  rep(i,n){
    cin >> a.at(i);
    suma+=a.at(i);
  }
  rep(i,n){
    cin >> b.at(i);
    sumb+=b.at(i);
  }
  if(sumb>suma){
    cout << -1;
    return 0;
  }
  ll p=0,ans=0;
  rep(i,n){
    if(b.at(i)-a.at(i)>0){
      p+=b.at(i)-a.at(i);
      ans++;
    }
  }
  vector<ll> an;
  rep(i,n){
    if(a.at(i)>b.at(i)){
      an.push_back(a.at(i)-b.at(i));
    }
  }
  sort(an.begin(),an.end());
  reverse(an.begin(),an.end());
  rep(i,n){
    if(p<=0){
      break;
    }
    p-=an.at(i);
    ans++;
  }
  cout << ans;
}