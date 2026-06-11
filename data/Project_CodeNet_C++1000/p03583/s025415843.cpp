#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(int)n;i++)
#define rep2(i,l,r) for(ll i=l;i<(int)r;i++)


int main(){
  ll n;cin >> n;
  rep2(i,1,3501)rep2(j,1,3501){
    if((4*i*j-n*(i+j))<=0)continue;
    if(n*i*j%(4*i*j-n*(i+j))==0){
      printf("%lld %lld %lld\n",i,j,n*i*j/(4*i*j-n*(i+j)));
      return 0;
    }
  }
  cout << fixed << setprecision(10);
  
}