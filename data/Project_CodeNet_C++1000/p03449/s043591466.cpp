#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int n;cin>>n;
  vector<int> a(n),b(n);
  int s=0,s_,ans;
  rep(i,n){
    cin>>a.at(i);
    s+=a.at(i);      
  }
  rep(i,n){cin>>b.at(i);}
  s+=b.at(n-1);
  ans=s;
  for(int i=n-1; i>0; i--){
    s_=s;
    s=s-a.at(i)+b.at(i-1);
    ans=max(ans,s);
  }
  cout<<ans;
}