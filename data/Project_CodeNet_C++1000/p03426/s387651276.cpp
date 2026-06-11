#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
long long gcd(long long a,long long b){
    ll gcdmax=max(a,b);
    ll gcdmin=min(a,b);
    while(true){
        if(gcdmax%gcdmin==0)break;
        else gcdmax%=gcdmin;
        swap(gcdmin,gcdmax);
    }
    return gcdmin;
}
ll powerup(ll N,ll P,ll M){
    if(P==0)return 1;
    else if(P%2==0){
        ll t=powerup(N,P/2,M);
        return t*t%M;
    }
    else return N*powerup(N,P-1,M)%M;
}
vector<ll> find_divisor(ll N){
  ll k=1;
  while(k*k<=N){
    k++;
  }
  vector<ll> A(1);
  rep(i,k){
    if(i==1)A.at(0)=1;
    else if(i>=2){
      if(N%i==0)A.push_back(i);
    }
  }
  ll t=0;
  t=A.size();
  rep(i,t){
    if(A.at(t-i-1)*A.at(t-i-1)!=N)A.push_back(N/A.at(t-1-i));
  }
  return A;
}
int main()
{
  ll H,W,D;
  cin>>W>>H>>D;
  vector<pair<ll,ll>> A(H*W+1);
  ll b;
  rep(i,W){
    rep(j,H){
      cin>>b;
      A.at(b).first=i;
      A.at(b).second=j;
    }
  }
  vector<ll> P(H*W+1);
  rep(i,H*W+1){
    if(i>D)P.at(i)=P.at(i-D)+abs(A.at(i).first-A.at(i-D).first)+abs(A.at(i).second-A.at(i-D).second);
  }
  ll Q,L,R;
  cin>>Q;
  rep(i,Q){
    cin>>L>>R;
    cout<<P.at(R)-P.at(L)<<endl;
  }
}