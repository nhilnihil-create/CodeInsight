#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n,k;cin>>n>>k;
  ll ans=0;
  for(int b=k+1;b<=n;b++){
    int p=n/b,r=n-p*b;
    ans+=(ll)(p*(b-k)+max(0,r-k+1));
    if(k==0) ans--;
  }
  cout<<ans;
}