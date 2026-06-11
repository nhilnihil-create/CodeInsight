#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long n,m; 
  cin >> n>>m;
  string s,t;
  cin>>s>>t;
  long g=__gcd(n,m);
  bool ch=true;
  rep(i,g){
    if(s.at(i*n/g)!=t.at(i*m/g)){
      ch=false;
    }
  }
  
  if(ch){
    long ans=n*m/g;
    cout<<ans<<endl;
  }
  else{
    cout<<-1<<endl;
  }
  
}