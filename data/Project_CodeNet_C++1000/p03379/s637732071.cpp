#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,z,i;
  cin>>n;
  vector<pair<int,int>> x,y;
  for(i=0;i<n;i++){
    cin>>z;
    x.push_back(make_pair(z,i+1));
  }
  sort(x.begin(),x.end());
  for(i=1;i<=n;i++){
    if(i<=n/2) y.push_back(make_pair(x.at(i-1).second,x.at(n/2).first));
    else if(i>=n/2+1) y.push_back(make_pair(x.at(i-1).second,x.at(n/2-1).first));
  }
  sort(y.begin(),y.end());
  for(auto w:y) cout<<w.second<<endl;
}