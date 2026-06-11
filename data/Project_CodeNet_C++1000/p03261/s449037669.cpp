#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,y;
  cin>>n;
  vector<string> w(n);
  for(int i=0;i<n;i++){
    cin>>w[i];
  }
  int sum=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(w[i]==w[j]){
        sum++;
      }
    }
  }
  for(int i=0;i<n-1;i++){
    if(w[i][w[i].size()-1]!=w[i+1][0]){
      sum++;
    }
  }
  if(sum>0){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}