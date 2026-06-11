#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> w(n);
  for(int i=0;i<n;i++){
    cin>>w[i];
  }
  bool ans=true;
  for(int i=0;i<n-1;i++){
    if(w[i+1][0]!=w[i][w[i].size()-1]){
      ans=false;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(w[i]==w[j]){
        ans=false;
      }
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}