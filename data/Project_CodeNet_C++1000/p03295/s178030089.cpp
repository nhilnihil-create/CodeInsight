#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  ll N,M;cin>>N>>M;
  vll a(M),b(M);
  rep(i,M){cin>>a[i]>>b[i];a[i]--,b[i]--;}
  int sec=0;
  vector<pair<int,int>> v;
  rep(i,M) v.emplace_back(a[i],b[i]);
  sort(all(v),[&](auto const& a,auto const& b){ return a.second<b.second;});
  ll cnt=1;
  sec = v[0].second-1;
  rep(i,M){
    if(v[i].first<=sec) continue;
    sec = v[i].second-1;
    cnt++;    
  }
  cout << cnt << endl;
}