#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main() {
  string s;
  cin>>s;
  int n=s.size();
  vector<char>q;
  vector<int>p(n+1);
  int j=0;
  rep(i,s.size()){
    if(s.at(i)!='x'){
      q.push_back(s.at(i));
      j++;
    }
    else{
      p[j]++;
    }
  }
  bool ex=true;
  rep(i,q.size()/2){
    if(q.at(i)!=q.at(q.size()-i-1)){
      ex=false;
    }
  }
  int ans=0;
  if(ex){
    rep(i,(q.size()-1)/2+1){
      ans+=abs(p[i]-p[q.size()-i]);
    }
  }
  if(ex){
    cout<<ans<<endl;
  }
  else{
    cout<<-1<<endl;
  }
}


