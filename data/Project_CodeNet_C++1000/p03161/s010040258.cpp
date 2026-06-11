#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> height;
    int l;
  for(int i=0;i<n;i++){
    cin>>l;
    height.push_back(l);
  }
  vector<int> X(n,INT_MAX);
  X[0]=0;
 for(int i=0;i<n-1;i++){
 for(int j=1;j<=k;j++){
   if(i+j>=n){
     break;
 }
   X[i+j]=min(X[i+j],X[i]+abs(height[i]-height[i+j]));
 }}
  cout<<X[n-1]<<"\n";
}