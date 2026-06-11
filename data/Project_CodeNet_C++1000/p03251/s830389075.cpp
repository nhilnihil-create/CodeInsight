#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
int main() {
  ll n,m,x,y;
  cin >> n >> m >> x >> y;
  vl a(n+1),b(m+1);
  rep(i,n){
    cin >> a[i];
  }
  a[n]=x;
  rep(i,m){
    cin >> b[i];
  }
  b[m]=y;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(a[n]<b[0])
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}