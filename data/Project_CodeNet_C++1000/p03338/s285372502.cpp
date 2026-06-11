#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k,ans=0;
  string s;
  vector<vector<int>> z(26,vector<int>(2));
  cin>>n>>s;
  for(i=0;i<n;i++){
    if(z.at(s.at(i)-'a').at(0)==0) z.at(s.at(i)-'a').at(0)=i+1;
    else z.at(s.at(i)-'a').at(1)=i+1;
  }
  for(i=1;i<n;i++){
    k=0;
    for(j=0;j<26;j++) if(z.at(j).at(0)<=i&&i<z.at(j).at(1)) k++;
    if(ans<k) ans=k;
  }
  cout<<ans<<endl;
}