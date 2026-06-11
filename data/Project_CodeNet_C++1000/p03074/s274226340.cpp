#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  vector<int> r;
  if(s[0]=='0') r.push_back(0);
  bool f0=1,f1=1;
  int tmp=0;
  rep(i,n){
    if(s[i]=='0'){
      if(f0) {tmp++; f1=0;}
      else {r.push_back(tmp); tmp=1; f1=0, f0=1;}
    }
    if(s[i]=='1'){
      if(f1) {tmp++; f0=0;}
      else {r.push_back(tmp); tmp=1; f1=1, f0=0;}
    }
  }
  r.push_back(tmp);
  if(s[n-1]=='0') r.push_back(0);
  vector<int> a(r.size()+1);
  a[0]=0;
  rep(i,r.size()){
    a[i+1]=a[i]+r[i];
  }
  int ans=0;
  if(k>=r.size()/2) ans=n;
  else{
    for(int i=2*k+1; i<a.size(); i+=2){
      ans=max(ans,a[i]-a[i-(2*k+1)]);
    }
  }
  cout<<ans<<endl;
}
