#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n], dif[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(i==0)
      dif[0] = a[0];
    else{
      dif[i] = a[i]- a[i-1];
    }
  }
  int ans=0;
  for(int i=0; i<n; i++){
    if(dif[i]>0){
      ans += dif[i];
    }
  }
  cout << ans << endl;
  return 0;
}