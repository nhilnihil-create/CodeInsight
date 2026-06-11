#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >>n;
  int a=0;
  int b=0;
  int c=0;
  int ans=0;
  rep(i,n){
    string s;
    cin>>s;
    if(s.at(s.size()-1)=='A'&&s.at(0)=='B'){
      c++;
    }
    else if(s.at(s.size()-1)=='A'){
      a++;
    }
    else if(s.at(0)=='B'){
      b++;
    }
    rep(i,s.size()-1){
      if(s.at(i)=='A'&&s.at(i+1)=='B'){
        ans++;
      }
    }
  }
  if(a>0&&b>0){
    ans+=c;
  }
  else if((a==0&&b!=0)||(a!=0&&b==0)){
    ans+=c;
  }
  else{
    ans+=max(c-1,0);
  }
  int mi=min(a,b);
  mi=min(mi,n-1);
  ans+=mi;
  
  cout<<ans<<endl;  
}

