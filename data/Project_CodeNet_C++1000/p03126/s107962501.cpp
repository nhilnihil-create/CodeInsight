#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<int>k(n);
  vector<vector<int>>a(n,vector<int>(m));
  for(int i=0;i<n;i++){
    cin>>k.at(i);
    for(int j=0;j<k.at(i);j++){
      cin>>a.at(i).at(j);
    }
  }
  int ans=0;
  for(int i=0;i<m;i++){
    int A=0;
    for(int j=0;j<n;j++){
      for(int l=0;l<k.at(j);l++){
        if(i+1==a.at(j).at(l)){
          A++;
        }
      }
    }
    if(A==n){
      ans++;
    }
  }
  cout<<ans<< endl;
}
        
      

