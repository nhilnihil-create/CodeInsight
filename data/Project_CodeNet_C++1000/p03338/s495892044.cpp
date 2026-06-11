#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int n;string s;
  cin>>n>>s;
  set<int> ss3;
  int ans=0;
  rep(i,n){ss3.insert(s.at(i));}
  rep(i,n){
    set<int> ss1,ss2;
    string s1=s.substr(0,i);
    string s2=s.substr(i,n-i);
    
    rep(j,n-i){
      ss2.insert(s2.at(j));
    }
    
    rep(j,i){
      ss1.insert(s1.at(j));
    }
    
    int a=ss1.size()+ss2.size()-ss3.size();
    ans=max(ans,a);
  }
  cout<<ans;
}