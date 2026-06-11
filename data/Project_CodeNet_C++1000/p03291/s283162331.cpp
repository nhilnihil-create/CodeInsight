#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  string s;
  cin >> s;
  int n=s.size();
  vector<ll> a(mx,0),b(mx,0),c(mx,0),d(mx,0);
  d[0]=1;
  
  rep(i,n){
    if(s[i]=='A'){
      d[i+1]=d[i]; 
      a[i+1]=(a[i]+d[i])%mod;
      b[i+1]=b[i];
      c[i+1]=c[i];
    }
    if(s[i]=='B'){
      d[i+1]=d[i];
      a[i+1]=a[i];
      b[i+1]=(a[i]+b[i])%mod;
      c[i+1]=c[i];
    }
    if(s[i]=='C'){
      d[i+1]=d[i];
      a[i+1]=a[i];
      b[i+1]=b[i];
      c[i+1]=(b[i]+c[i])%mod;
    }
    if(s[i]=='?'){
      d[i+1]=(d[i]*3)%mod;
      a[i+1]=(a[i]*3+d[i])%mod;;
      b[i+1]=(a[i]+b[i]*3)%mod;
      c[i+1]=(b[i]+c[i]*3)%mod;
    }
  }

  ll ans=c[n];
  cout << ans << endl;
  return 0;
}