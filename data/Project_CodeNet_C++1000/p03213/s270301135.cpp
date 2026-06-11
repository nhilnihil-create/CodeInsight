#include <iostream>
#include <vector>
using namespace std; using P=pair<int,int>; using ll=long long;

int main() {
  ll n; cin>>n;
  ll b[n+1]; fill(b,b+n+1,0);
    for(ll j=1;j<=n;j++) {
      ll j2=j;
      for(ll k=2;k<=j2;k++) {
        if (j2%k==0) j2/=k, b[k]++, k--;
      }
    }
  /*
  for(int i=0;i<=n;i++) {
    cout<<b[i]<<" ";
  } cout<<endl;*/

  ll an=0;
  for(int i=2;i<=n;i++) {
    for(int j=2;j<=n-1;j++){
      for(int k=j+1;k<=n;k++) {
        if (i==j || j==k || i==k) continue;
        if (b[i]>=2 && b[j]>=4 && b[k]>=4) an++;
      }
    }
  }

  for(int i=2;i<=n;i++) {
    for(int j=2;j<=n;j++) {
      if (i==j) continue;
      if (b[i]>=2 && b[j]>=24) an++;
      if (b[i]>=4 && b[j]>=14) an++;
    }
  }
  for(int i=2;i<=n;i++) {
    if (b[i]>=74) an++;
  }
  cout<<an<<endl;
}