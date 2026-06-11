#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,ans=0;
  string s,t;
  map<string,int> z;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>s;
    if(z.count(s)) z.at(s)++;
    else z[s]=1;
  }
  cin>>m;
  for(i=0;i<m;i++){
    cin>>t;
    if(z.count(t)) z.at(t)--;
    else z[t]=-1;
  }
  for(auto y:z) if(ans<y.second) ans=y.second;
  cout<<ans<<endl;
}