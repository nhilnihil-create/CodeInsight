#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; } template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  ll n;cin>>n;
  vector<ll> a(n),b(n);
  vector<P> p(n);
  rep(i,n){
    cin>>a[i]>>b[i];
    p[i]=P(a[i]+b[i],i);
  }
  sort(all(p),greater<P>());
  ll d=0LL,e=0LL;
  rep(i,n){
    ll f=p[i].second;
    if(i%2){
      e+=b[f];
    }else{
      d+=a[f];
    }
  }
  cout<<d-e;
}