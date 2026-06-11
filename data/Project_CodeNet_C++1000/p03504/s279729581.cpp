#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,j,n) for(int i=j;i<n;i++)
int main(){
  int N,C;cin>>N>>C;
  vector<int> s(N),t(N),c(N),cnt(200010);
  rep(i,N) cin>>s[i]>>t[i]>>c[i];
  REP(i,1,C+1){
	vector<int> table(2000010);
    rep(j,N) {
      if(c[j]==i) {
        table[s[j]*2-1]++,table[t[j]*2]--;
      }
    }
    REP(j,1,2000010) table[j]+=table[j-1];
    rep(j,2000010) if(table[j]>0) cnt[j]++;
  }
  int ans=0;
  for(auto p:cnt) ans=max(ans,p);
  cout<<ans<<endl;
}
    