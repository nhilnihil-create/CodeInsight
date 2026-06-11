#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int  main(){
  int n,c,ans=0,l,r;cin>>n;
  vector<int> v(n);
  rep(i,n){cin>>v.at(i);}
  while(true){
    if(count(v.begin(),v.end(),0)==n){break;}
   
    c=0;
    if(v.at(0)!=0)c++;
    for(int i=0; i<n-1; i++){
      if(v.at(i)==0&&v.at(i+1)!=0){c++;}
    }
    ans+=c;
    rep(i,n){
      if(v.at(i)!=0){v.at(i)--;}
    }
  }
  cout<<ans;
}