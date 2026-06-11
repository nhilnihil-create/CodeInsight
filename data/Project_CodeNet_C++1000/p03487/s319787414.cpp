#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  sort(a.begin(), a.end());

  ll ans=0;
  int j=0;
  while(j<n){
    ll now=a.at(j);
    int count=0;
    while(j<n&&a.at(j)==now){j++; count++;}
    if(count>=now) ans+=(count-now);
    else ans+=count; 
  }

  cout << ans;
}