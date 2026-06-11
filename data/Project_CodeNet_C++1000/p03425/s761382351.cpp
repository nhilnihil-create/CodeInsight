#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e14+4;
const int Nmax=2e5+1;
const int Nd=61;

int main(){
  int n; cin>>n;
  vector<string> name(n);
  vector<ll> m(5,0);
  rep(i,n) {
    cin>>name[i];
    //cout<<name[i][0];
    if(name[i][0]=='M') m[0]++;
    if(name[i][0]=='A') m[1]++;
    if(name[i][0]=='R') m[2]++;
    if(name[i][0]=='C') m[3]++;
    if(name[i][0]=='H') m[4]++;
  }

  ll ans=0;
  ll now=0;
  rep(i,4){
    for(int j=i+1;j<5;j++){// i,jを除く
      now=1;
      rep(k,5){
        if(k!=i && k!=j){
          now*=m[k];
        }
      }
      ans+=now;
    }
  }
  cout<<ans<<endl;







  return 0;
}
