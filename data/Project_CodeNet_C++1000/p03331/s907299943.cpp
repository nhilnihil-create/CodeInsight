#include <bits/stdc++.h>
#define ll long long
using namespace std;

int digit(int x){
  int z=0;
  while(x>0){
    z+=x%10;
    x/=10;
  }
  return z;
}

int main(){
  int n;
  cin>>n;
  int ans=10000;
  for(int i=1;i<=n/2;i++){
    ans=min(ans,digit(i)+digit(n-i));
  }
  cout<<ans<<endl;
  return 0;
}