#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int z=500;
  int ans=0;
  for(int i=0;i<n-1;i++){
    if(vec[i]==vec[i+1]){
      ans++;
      vec[i+1]=z;
      z++;
    }
  }
  cout<<ans<<endl;
}