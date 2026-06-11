#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
char s1[305][305]={0};
int main(){
  ll n;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin>>s1[i][j];
  }
  ll ans=0;
  for(int del=-n;del<=n;del++){
    bool f=true;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        ll nx=(j+n-del)%n,ny=(i+n+del)%n;
        if(s1[i][j]!=s1[nx][ny]) f=false;
      }
    }
    if(f) ans+=n-abs(del);
  }
  cout<<ans<<endl;
}
