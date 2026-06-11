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
  ll n,x;
  cin >> n >> x;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll cnt=0;
  rep(i,n){
    if(i!=n-1){
      if(x>=a[i]){
        cnt++;
        x -=a[i];
      }
    }
    else{
      if(x==a[i]){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}