#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  int a[2][n];
  for(int i=0;i<2;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<=i;j++){
      sum+=a[0][j];
    }
    for(int k=i;k<n;k++){
      sum+=a[1][k];
    }
    if(ans<sum){
      ans=sum;
    }
  }
  cout<<ans<<endl;
  return 0;
}