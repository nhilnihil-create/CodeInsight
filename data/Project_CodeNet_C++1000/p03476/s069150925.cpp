#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  vector<bool> primes(100007,true);
  primes[0]=false;
  primes[1]=false;
  for(ll i=2;i*i<100007;i++){
      if(!primes[i])continue;
      for(ll j=2;i*j<100007;j++){
          primes[i*j]=false;
      }
  }
  ll q;
  cin>>q;
  vl a(100007,0);
  for(ll i=3;i<100007;i++){
      if(i%2==1&&primes[i]&&primes[(i+1)/2]){
          a[i]=a[i-1]+1;
      }
      else{
          a[i]=a[i-1];
      }
  }
  rep(i,q){
      ll l,r;
      cin>>l>>r;
      ll ans=a[r]-a[l-1];
      print(ans);
  }
}
