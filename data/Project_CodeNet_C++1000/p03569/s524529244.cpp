#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
using ll = long long int;

int main() {
  string s; cin>>s;
  vector<int> v;
  string t="";
  rep(i,s.size()){
    if(s[i]!='x'){
      v.push_back(i);
      t+=s[i];
    }
  }
  string tr;
  tr= t;
  reverse(tr.begin(), tr.end());
  if(t.size()==0 ){cout<<0<<endl;}
  else if( tr!= t){cout<<-1<<endl;}
  else{
    vector<int> vec(t.size()+1);
    rep(i,t.size()+1){
      if(i==0){vec[i]=v[0];}
      else if(i==t.size() ){vec[i]=s.size()-v[i-1]-1;}
      else{vec[i]=v[i]-v[i-1]-1;}
    }
    int ans=0;
    rep(i,t.size()+1){
      ans+=abs(vec[i]-vec[vec.size()-i-1] );
    }
   // if(vec.size() %2==1){
    //  ans-= vec[vec.size()/2];
    //}
    ans/=2;
    cout<<ans<<endl;
  }
}