#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
 int n;
  cin>>n;
  vin a(n);
  rep(i,n) cin>>a[i];
  //////map
  ll ans=0;
  map<int,int> mp;
  rep(i,n){
    mp[a[i]]++;
  }
  for(auto v:mp){
    if(v.first >v.second){
      ans+=v.second;
    }
    else if(v.first<v.second){
       ans+=v.second-v.first;
    }
  }
  cout<<ans<<endl;
}