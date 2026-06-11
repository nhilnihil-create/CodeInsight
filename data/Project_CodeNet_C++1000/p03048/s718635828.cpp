#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int r,g,b,n,ans=0;
  cin>>r>>g>>b>>n;
  for(int i=0;i<4000;i++){
    for(int j=0;j<4000;j++){
      int k=i*r+j*g;
      if(n-k>=0&&(n-k)%b==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}