#include<iostream>
using namespace std;

int main(){
  int n;cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans=0;
  int tmp=1;
  for(int i=0;i<n-1;i++){
    if(a[i]==a[i+1]) tmp++;
    else if(tmp>1){
      ans+=tmp/2;
      tmp=1;
    }
  }
  ans+=tmp/2;
  cout<<ans<<endl;
  return 0;
}