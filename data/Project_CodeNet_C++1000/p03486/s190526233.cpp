#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  string s,t; cin>>s>>t;
 
  vector<char> v1(s.size()),v2(t.size());
  rep(i,s.size()){v1[i]=s.at(i);}
  sort(v1.begin(),v1.end());
  string s_="";
  rep(i,s.size()){s_+=v1[i];}

  rep(i,t.size()){v2[i]=t.at(i);}
  sort(v2.begin(),v2.end(),greater<char>());
  string t_="";
  rep(i,t.size()){t_+=v2[i];}
  vector<string> vec(2);
  vec[0]=s_;vec[1]=t_;
  sort(vec.begin(),vec.end());
  if(vec[0]==vec[1]){cout<<"No";}
  else if(vec[0]==s_){cout<<"Yes";}
  else{cout<<"No";}
}

