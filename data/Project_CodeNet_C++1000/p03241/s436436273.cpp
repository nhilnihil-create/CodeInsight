#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin>>n>>m;
  int p=min((int)sqrt(m),m/n);
  int ans=0;
  for(int i=1;i<=p;i++){
    if(m%i==0){
      ans=max(ans,i);
      if(m/i<=m/n){
        ans=m/i;
        break;
      }
    }
  }
  cout<<ans<<endl;
}