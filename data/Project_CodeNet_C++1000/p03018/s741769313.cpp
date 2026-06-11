#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  cin>>s;
  s='X'+s+'X';
  int n=s.size();
  ll ans=0;
  if(n<3){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<s.size()-2;i++){
    if(s[i]=='B'&&s[i+1]=='C'){
      s.insert(i+2,"D");
      s.erase(i,2);
    }
  }
  //cout<<s<<endl;
  int j,stop;
  ll vec[s.size()];
  vec[0]=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A'){
      vec[i]=vec[i-1]+1;
    }
    else{
      vec[i]=vec[i-1];
    }
  }
  for(int i=1;i<s.size();i++){
    if(s[i]=='B'||s[i]=='C'||s[i]=='X'){
      stop=i;
      continue;
    }
    if(s[i]=='D'){
      ans+=vec[i]-vec[stop];
    }
  }
  cout<<ans<<endl;
}