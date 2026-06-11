#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin>>n;
  ll ans=0;
  for(ll i=1;i*i<n;i++){
    ll res=n/i-1;
    if(n%i==0&&n/res==n%res) ans+=res;
  }
  cout<<ans<<endl;
}