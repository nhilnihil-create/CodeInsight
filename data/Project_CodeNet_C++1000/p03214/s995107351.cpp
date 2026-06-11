//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  vector<double> a(n);
  rep(i,n)cin>>a[i];
  double ave=0;
  rep(i,n)ave+=a[i];
  ave/=n;
  double MIN=INF;
  ll k=-1;
  rep(i,n){
    if(abs(ave-a[i])<MIN){
      k=i;
      MIN=abs(ave-a[i]);
    }
  }
  cout<<k<<endl;
}