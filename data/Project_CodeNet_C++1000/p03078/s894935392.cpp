#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int X,Y,Z;
ll K;
ll A[1010],B[1010],C[1010];

bool solve(ll mid){
  ll sum=0;
  rep(i,X) rep(j,Y){
    int k=lower_bound(C,C+Z+1,mid-(A[i]+B[j]))-C;
    sum+=Z-k;
  }
  return (sum>=K);
}

void ans(ll l){
  vector<ll> res;
  rep(i,X) rep(j,Y){
    int tmp=upper_bound(C,C+Z+1,l-(A[i]+B[j]))-C;
    for(int k=tmp;k<Z;k++) res.push_back(A[i]+B[j]+C[k]);
  }
  int siz=res.size();
  for(int i=0;i+siz<K;i++) res.push_back(l);
  sort(res.rbegin(),res.rend());
  for(ll r:res) cout<<r<<endl;
}

int main(){
  cin>>X>>Y>>Z>>K;
  rep(i,X) cin>>A[i];
  rep(i,Y) cin>>B[i];
  rep(i,Z) cin>>C[i];
  sort(C,C+Z);
  C[Z]=1e15;
  ll l=0,r=1e11;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(solve(mid)) l=mid;
    else r=mid;
  }
  ans(l);
  return 0;
}