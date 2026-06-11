#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll INF=1e6;
const int Nmax=2e5+1;
const int Nd=61;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;} //最大公約数


int main(){
  int n; cin>>n;
  vector<int> a(n);
  int ans=0;
  rep(i,n){
    cin>>a[i];
    if(i==0)  ans=a[0];
    else ans=gcd(ans,a[i]);
  }
  cout<<ans<<endl;


}
