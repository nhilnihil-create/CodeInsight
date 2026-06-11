#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  ans+=(n/k)*(n/k)*(n/k);
  if(k%2==0){
    ans+=((n+k/2)/k)*((n+k/2)/k)*((n+k/2)/k);
  }
  cout<<ans<<endl;
}