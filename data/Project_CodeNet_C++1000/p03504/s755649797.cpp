#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  vector<int> s(n),l(n),c(n);
  for(int i=0;i<n;i++){
    cin>>s[i]>>l[i]>>c[i];
  }
  vector<int> tt(200010,0),sm(200010,0);
  for(int i=1;i<=m;i++){
    for(int j=0;j<200010;j++) tt[j]=0;
    for(int j=0;j<n;j++){
      if(i==c[j]){
        tt[s[j]*2-1]++; tt[l[j]*2]--;
      }
    }
    for(int j=1;j<200010;j++) tt[j]+=tt[j-1];
    for(int j=0;j<200010;j++) if(tt[j]>0) sm[j]++;
  }
  int ans=0;
  for(int i=0;i<200010;i++) if(sm[i]>ans) ans=sm[i];
  cout<<ans<<endl;
}