#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,s,t,c,i,j,ans=0,tmax=1e5;
  cin>>n>>m;
  vector<vector<int>> v(m,vector<int>(tmax+1));
  for(i=0;i<n;i++){
    cin>>s>>t>>c;
    v.at(c-1).at(s)++;
    v.at(c-1).at(t)--;
  }
  for(i=0;i<m;i++){
    for(j=1;j<=tmax;j++){
      v.at(i).at(j)+=v.at(i).at(j-1);
      if(v.at(i).at(j-1)==0&&v.at(i).at(j)==1) v.at(i).at(j-1)=1;
    }
  }
  for(j=0;j<=tmax;j++){
    c=0;
    for(i=0;i<m;i++) c+=v.at(i).at(j);
    ans=max(ans,c);
  }
  cout<<ans<<endl;
}