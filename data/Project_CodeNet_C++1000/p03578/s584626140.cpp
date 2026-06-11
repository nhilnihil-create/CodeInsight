#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph = vector<vector<char>>;

int main(){
  ll n,m; cin>>n;
  vector<ll> v(n);
  rep(i,n){cin>>v[i];}
  sort(v.begin(),v.end());
  
  cin>>m;
  vector<ll> vc(m);
  rep(i,m){cin>>vc[i];}
  sort(vc.begin(),vc.end());
  
  ll i=0;
  string  ans="YES";
  if(n<m){ans="NO";}
  else{
    rep(j,m){
      while(v[i]<vc[j]){i++;}
      if(v[i]==vc[j]){
        //cout<<i<<j<<endl;
        if(i==n-1&&j==m-1){break;}
        else{i++;continue;}}
      if(v[i]>vc[j]){ans="NO";break;}
      if(i==n-1&&j<m-1){ans="NO";break;}
    }
  }
  cout<<ans;
}

