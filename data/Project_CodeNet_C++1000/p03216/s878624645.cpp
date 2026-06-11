#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,q;
  string s;
  cin>>n>>s>>q;
  vector<int>k(q);
  rep(i,q)cin>>k[i];

  rep(query,q){
    int x=k[query];
    ll d=0,m=0,dm=0;
    ll ans=0;
    rep(i,x){
      if(s[i]=='D')d++;
      if(s[i]=='M')m++,dm+=d;
      if(s[i]=='C')ans+=dm;
    }
    for(int i=x; i<n; ++i){
      if(s[i-x]=='D')dm-=m,d--;
      if(s[i-x]=='M')m--;
      if(s[i]=='D')d++;
      if(s[i]=='M')m++,dm+=d;
      if(s[i]=='C')ans+=dm;
    }
    cout<<ans<<endl;
  }
}