#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> X(n);
  int k;
  for(int i=0;i<n;i++){
  for(int j=0;j<3;j++){
  	cin>>k;
    X[i].push_back(k);
  }
  }
  vector<int> a(3,0);
  vector<vector<int>>result(n,a);
  result[0][0]=X[0][0];
  result[0][1]=X[0][1];
  result[0][2]=X[0][2];
  
  for(int i=1;i<n;i++){
  for(int j=0;j<3;j++){
  if(j==0){
  result[i][j]=X[i][j]+max(result[i-1][1],result[i-1][2]);
  }
    else if(j==1){
       result[i][j]=X[i][j]+max(result[i-1][0],result[i-1][2]);
    }
    else{
       result[i][j]=X[i][j]+max(result[i-1][0],result[i-1][1]);
    }
  }
  }
  cout<<max(result[n-1][0],max(result[n-1][1],result[n-1][2]))<<"\n";
  
}