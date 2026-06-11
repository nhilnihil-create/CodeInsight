#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n;
  cin>>n;
  vector<int> e(n+1,0),w(n+1,0);
  char c;
  for(int i=0;i<n;++i){
    cin>>c;
    if(c=='W')w[i+1]=w[i]+1,e[i+1]=e[i];
    if(c=='E')e[i+1]=e[i]+1,w[i+1]=w[i];
  }

  ll m=300010,cnt;
  for(int i=1;i<n+1;++i){
    ll we=e[n]-e[i];
    ll ea=w[i-1];
    cnt=we+ea;
    m=min(m,cnt);
  }
  cout<<m;
}