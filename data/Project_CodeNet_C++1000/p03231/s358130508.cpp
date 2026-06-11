#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

ll gcd(ll a,ll b){
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}

ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main(){
  ll n,m;
  cin >> n >> m;
  string s,t; cin >> s >> t;
  ll l=lcm(n,m);
  ll dn=l/n;
  ll dm=l/m;
  ll dl=lcm(dn,dm);
  ll di=dl/dn;
  ll dj=dl/dm;
  int i=0,j=0;
  bool f=1;
  while(i<n&&j<m){
    if(s[i]!=t[j]) f=0;
    i+=di; j+=dj;
  }
  if(f) cout << l << endl;
  else cout << -1 << endl;
  
}