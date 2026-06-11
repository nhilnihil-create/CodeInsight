#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
ll gcd(ll x, ll y){
  if(y==0) return x;
  else return gcd(y, x%y);
}
ll lcm(ll x,ll y){
  ll g=gcd(x,y);
  return x/g*y;
}
 
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int ans;
  if(A+B<2*C){
    ans=A*X+B*Y;
  }
  else{
    ans=min(X,Y)*C*2;
    int Z=min(X,Y);
    X-=Z;
    Y-=Z;
    if(Y==0){
      if(A<2*C) ans+=A*X;
      else ans+=X*C*2;
    }
    if(X==0){
      if(B<2*C) ans+=B*Y;
      else ans+=Y*C*2;
    }
  }
  cout<<ans<<endl;
}
  

