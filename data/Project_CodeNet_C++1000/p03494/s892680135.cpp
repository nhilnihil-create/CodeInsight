#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  cin>>n;
  int a;
  int ans=200000;
  rep(i,n){
    cin>>a;
    int cnt=0;
    while(a%2==0){
      a/=2;
      cnt++;
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}