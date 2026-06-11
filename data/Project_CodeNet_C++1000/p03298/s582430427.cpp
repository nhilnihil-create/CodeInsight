#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<string,string> P;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  string lstr=s.substr(0,n),rstr=s.substr(n,n);
  map<P,ll> mp;
  for(int i=0;i<(1<<n);i++){
    string ks,k2;
    for(int j=0;j<n;j++){
      if(((i>>j)&1)==1){
        ks.push_back(lstr[j]);
      }
    }
    for(int j=n-1;j>=0;j--){
      if(((i>>j)&1)==0){
        k2.push_back(lstr[j]);
      }
    }
    P p=P(ks,k2);
    auto itr=mp.find(p);
    if(itr!=mp.end()) mp[p]++;
    else mp[p]=1;
  }
  ll ans=0;
  for(int i=0;i<(1<<n);i++){
    string kr,k2;
    for(int j=n-1;j>=0;j--){
      if(((i>>j)&1)==1) kr.push_back(rstr[j]);
    }
    for(int j=0;j<n;j++){
      if(((i>>j)&1)==0) k2.push_back(rstr[j]);
    }
    P p=P(kr,k2);
    auto itr=mp.find(p);
    if(itr!=mp.end()){
     ans+=mp[p];
     //cout<<mp[kr]<<" "<<kr<<endl;
    }
  }
  cout<<ans<<endl;
}
