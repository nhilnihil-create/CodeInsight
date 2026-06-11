#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rrep1(i,n) for(ll i=n;i>=1;i--)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
const ll MOD=1000000007;
const double INF=1000000000000000.0;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}

int main(){
    ll A,B; cin>>A>>B;
  if(A+B==15) cout<<"+";
  else if(A*B==15) cout<<"*";
  else cout<<"x";
}