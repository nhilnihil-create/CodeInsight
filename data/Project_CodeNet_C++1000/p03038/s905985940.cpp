#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);

  vector<pair<ll, ll>> sousa;
  rep(i,m){
    ll b,c;
    cin >> b >> c;
    sousa.push_back(make_pair(c,b));
  }

  sort(sousa.rbegin(), sousa.rend());
  sort(a.begin(), a.end());

  int count=0;
  int i=0;
  while(i<n){
    if(count>=m) break;   
    
    ll b,c;
    b = sousa.at(count).second;
    c = sousa.at(count).first;
    int change=0;
    
    while(i<n&&a.at(i)<c&&change<b){
      a.at(i) = c;
      i++;
      change++;
    }

    if(!change) break;
    count++;
  }

  ll ans=0;
  rep(i,n) ans+=a.at(i);
  cout << ans;
  //rep(i,n) cout << a.at(i) << " ";  
  
}