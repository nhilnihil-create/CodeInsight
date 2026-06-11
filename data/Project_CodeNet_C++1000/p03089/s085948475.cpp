#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
  int n; cin>>n;
  vector<pii> v(n);
  rep(i,n){
    cin>>v[i].second;  
    v[i].second--;
  }

  vector<int> num(n);
  rep(i,n){
    num[i]=i;
  }//int x=2;num.erase(num.begin()+x);
  int ans=0;
  rep(i,n){
    int x=v[n-i-1].second;
    if(num.size()<x+1){ans=-1;break;}
    v[n-i-1].first=num[x];
    num.erase(num.begin()+x);
  }
  if(ans==0){
    sort(v.begin(), v.end());
    rep(i,n){cout<<v[i].second+1<<endl;}
  }
  else{cout<<ans;}
}

