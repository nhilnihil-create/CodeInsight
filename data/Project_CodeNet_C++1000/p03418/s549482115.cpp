#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  ll ans=0;
  rep(i,k+1,n+1){
    ans+=(n+1)/i*(i-k)+max(0,(n+1)%i-k);
  }
  if(k==0) ans-=n;
  cout<<ans<<endl;
}