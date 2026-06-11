#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  ll n;
  cin>>n;
  int l=-1;
  for(ll i=1;i<=n;i++){
    if(i*i+i-2*n==0){
      l=i;
    }
  }
  if(l==-1){
    cout<<"No"<<endl;
    return(0);
  }
  vector<vector<int>>s(l+1,vector<int>(l));

  int cnt=1;
  rep(i,l){
    rep2(j,i,l){
      s[i][j]=cnt;
      cnt++;
    }
  }
  cnt=1;
  rep(i,l){
    rep2(j,i,l){
      s[j+1][i]=cnt;
      cnt++;
    }
  }

  cout<<"Yes"<<endl;
  cout<<l+1<<endl;
  rep(i,l+1){
    cout<<l<<' ';
    rep(j,l){
      cout<<s[i][j];
      if(j+1==l)cout<<endl;
      else cout<<' ';
    }
  }
  return(0);
}
