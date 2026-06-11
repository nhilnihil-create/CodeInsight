#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> d(m);
  int k;
  cin>>k;
  for(int i=0;i<n;i++){
    vector<int> w(k);
    for(int j=0;j<k;j++){
      cin>>w[j];
    }
    for(int j=0;j<k;j++){
      d[w[j]-1]++;
    }
    cin>>k;
  }
  int ans=0;
  for(int i=0;i<m;i++){
    if(d[i]==n){
      ans++;
    }
  }
  cout<<ans<<endl;
      
}