#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> a(2,vector<int> (n));
  for(int i=0;i<2;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    int x=0;
    int k=0;
    for(int j=0;j<n;j++){
      if(i==j){
        x+=a[k][j];
        k++;
        x+=a[k][j];
      }
      else{
        x+=a[k][j];
      }
    }
    if(x>ans){
      ans=x;
    }
  }
  cout<<ans<<endl;
}