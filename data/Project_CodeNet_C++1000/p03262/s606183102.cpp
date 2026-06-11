#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll N,X;
  cin>>N>>X;
  ll x[N];
  ll m[N];//Xとの差
  rep(i,N){
  cin>>x[i];
    m[i]=abs(X-x[i]);
  }
  ll ans=m[N-1];
  rep(i,N-1){
    ans=gcd(ans,m[i]);
  }
  
  cout<<ans<<endl;


}
