#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  string s;
  cin>>s;
  string ans="keyence";
  bool t=false;
  
  if(s==ans){cout<<"YES"<<endl;return 0;}
  string tmp="";
  
  rep(i,s.size()){
    Rep(j,i,s.size()){
      if(s.substr(0,i)+s.substr(j)==ans){t=true;}
	}
  }
  


    
  if(t)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
    
    
  return 0;
}
