#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  int n,m,ans=0;cin>>n>>m;
  if(m<=n)ans=0;
  
  else{
  vector<int> v(m);
  rep(i,m){cin>>v.at(i);}
  sort(v.begin(),v.end());
  vector<int> vec(m-1);
  rep(i,m-1){
    vec.at(i)=v.at(i+1)-v.at(i);
    ans+=vec.at(i);
    //cout<<vec.at(i)<<" ";
  }
  sort(vec.begin(),vec.end());
  rep(i,n-1){
    ans-=vec.at(m-i-2);
  }
  }
  
  cout<<ans;
  
}