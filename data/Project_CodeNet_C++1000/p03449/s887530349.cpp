#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0;
  cin >> n;
  int a[2][n];
  for(int i=0;i<2;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  int sum1=0,sum2=0;
  for(int i=0;i<n;i++){
    sum1+=a[0][i];
    for(int j=i;j<n;j++){
      sum2+=a[1][j];
    }
    ans=max(sum1+sum2,ans);
    sum2=0;
  }
  cout << ans << endl;
}