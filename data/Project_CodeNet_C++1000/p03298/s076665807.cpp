#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int n;
  string s;
  cin>>n>>s;
  string l,r;
  l=s.substr(0,n);
  r=s.substr(n,n);
  reverse(r.begin(),r.end());
  //cout<<l<<" "<<r<<endl;
  map<pair<string,string>,int> mp;
  for(int i=0;i<(1<<n);i++){
    string sl="";
    string sr="";
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
        sl.push_back(l[j]);
      }else{
        sr.push_back(l[j]);
      }
    }
    mp[make_pair(sl,sr)]++;
  }
  int ans=0;
  for(int i=0;i<(1<<n);i++){
    string sl="";
    string sr="";
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
        sl.push_back(r[j]);
      }else{
        sr.push_back(r[j]);
      }
    }
    ans+=mp[make_pair(sl,sr)];
  }
  cout<<ans<<endl;
}
