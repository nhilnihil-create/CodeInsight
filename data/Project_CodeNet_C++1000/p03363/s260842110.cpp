#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n;
  cin >> n;
  vl a(n);
  vl sum(n+1);
  sum[0]=0;
  rep(i,n){
    cin >> a[i];
    sum[i+1]=sum[i]+a[i];
  }
  sort(sum.begin(),sum.end());
  ll cnt=0;
  ll k=0;
  rep(i,n){
    if(sum[i]==sum[i+1]){
      k++;
    }
    else{
      cnt+=k*(k+1)/2;
      k=0;
    }
  }
  cnt+=k*(k+1)/2;
  cout << cnt << endl;
}