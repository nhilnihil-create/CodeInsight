#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll vec[n];
  int x=0,y=0;
  for(int i=0;i<n;i++){
    cin>>vec[i];
    if(vec[i]==0){
      x++;
    }
    if(vec[i]<0){
      y++;
    }
  }
  ll sum=0;
  for(int i=0;i<n;i++){
    sum+=abs(vec[i]);
  }
  if(x!=0||y%2==0){
    cout<<sum<<endl;
    return 0;
  }
  ll z=1e10;
  for(int i=0;i<n;i++){
    z=min(z,abs(vec[i]));
  }
  cout<<sum-2*z<<endl;
}