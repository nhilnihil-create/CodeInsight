#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int r,g,b,n;
  cin>>r>>g>>b>>n;
  int ans=0;
  for(int i=0;i<=n/r;i++){
    int m=n-r*i;
    for(int j=0;j<=m/g;j++){
      if((m-j*g)%b==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
