#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int r,g,b;
  cin>>r>>g>>b;
  int n;
  cin>>n;
  ll ans=0;
  for(int i=0; i*r<=n; i++){
    for(int j=0; i*r+j*g<=n; j++){
      if((n-(i*r+j*g))%b==0)ans++;
    }
  }
  cout<<ans<<endl;
}
