#include<iostream>
using namespace std;
const int INF=1e9;

int digit(int n){
  int res=0;
  while(n>0){
    res+=(n%10);
    n/=10;
  }
  return res;
}

int main(){
  int n;cin>>n;
  int ans=INF;
  for(int a=1;a<n;a++){
    int b=n-a;
    ans=min(ans,digit(a)+digit(b));
  }
  cout<<ans<<endl;
  return 0;
}