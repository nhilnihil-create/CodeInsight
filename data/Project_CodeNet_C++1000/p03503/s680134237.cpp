#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long ll;
int main(){
  int n,f;
  cin>>n;
  bitset<10> b[n];
  ll p[n][11], ans=LLONG_MIN;
  rep(i,n)
    rep(j,10){
       cin>>f;
       if(f)
        b[i].set(j); 
    }
  rep(i,n)
    rep(j,11)
       cin>>p[i][j];
  rep(i,1023){
     bitset<10> jo(i+1);
     ll sum=0;
     rep (j,n)
       sum+=p[j][(jo&b[j]).count()];
     ans=max(ans,sum);
  }
  cout<<ans;
  return 0;
}