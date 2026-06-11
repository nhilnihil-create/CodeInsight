#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<long long> x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  int max=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        break;
      }
      
      int d=x[i]-x[j];
      if(d<0){
        d=-d;
       }
      if(d>max){
        max=d;
      }
    }
  }
  cout<<max<<endl;
}