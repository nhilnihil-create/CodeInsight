#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int z=a[0];
  int x=1;
  int ans=0;
  for(int i=1;i<=n;i++){
    if(i==n){
      ans+=(x/2);
    }
    else if(z==a[i]){
      x++;
    }
    else{
      z=a[i];
      ans+=(x/2);
      x=1;
    }
  }
  cout<<ans<<endl;
}