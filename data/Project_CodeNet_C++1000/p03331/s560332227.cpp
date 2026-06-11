#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
ll digsum(ll n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
int main(){
  ll x ;
  cin >> x ;
  if(digsum(x)==1) cout <<10<<endl ;
  else
   cout<<digsum(x)<<endl; 
    return 0;
}