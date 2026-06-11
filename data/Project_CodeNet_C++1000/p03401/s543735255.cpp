#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main() {
ll N;
  cin >>N;
  
  vl A(N+2);
  A.at(0)=0;
  A.at(N+1)=0;
  repl(i,1,N+1) {
    cin>>A.at(i);
  }
  
  
  
  vl b(N+1);
  rep(i,N+1) {
    b.at(i)=abs(A.at(i+1)-A.at(i));
  }
  ll sum=0;
  rep(i,N+1) {
    sum +=b.at(i);
  }
  
  vl c(N);
  
  rep(i,N) {
c.at(i)=sum+abs(A.at(i+2)-A.at(i))-abs(A.at(i+1)-A.at(i))-abs(A.at(i+2)-A.at(i+1));
  }
  
  
  rep(i,N) {
cout<<c.at(i)<<endl;
  }
  
  
  
}
  
  
        
      
    
    
    
    
  