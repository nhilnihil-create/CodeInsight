#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  string s;
  cin>>n;
  cin>>s;

  ll ans=0;
  map<pair<string,string>,ll> mp;
  for(ll i=0;i<(1<<n);i++){
    ll tmp=i,count=n;
    string v,w;
    while(count<2*n){
      if(tmp%2) v=v+s[count];
      else w=s[count]+w;
      count++;
      tmp/=2;
    }
    //if(v.size()!=n||v.size()!=w.size()) continue;

    mp[make_pair(v,w)]++;
    reverse(v.begin(),v.end());
    reverse(w.begin(),w.end());
    mp[make_pair(w,v)]++;
  }

  for(ll i=0;i<(1<<n);i++){
    ll tmp=i,count=0;
    string v,w;
    while(count<n){
      if(tmp%2) v=v+s[count];
      else w=s[count]+w;
      count++;
      tmp/=2;
    }
    //if(v.size()!=n||v.size()!=w.size()) continue;

    if(mp[make_pair(w,v)]>0) ans+=mp[make_pair(w,v)];
    reverse(w.begin(),w.end());
    reverse(v.begin(),v.end());
    if(mp[make_pair(v,w)]>0) ans+=mp[make_pair(v,w)];
  }

  cout<<ans/4<<endl;

  return 0;
}
