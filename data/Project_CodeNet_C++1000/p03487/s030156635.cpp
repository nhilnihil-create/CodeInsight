#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n;
  cin>>n;
  vector<ll> p(100005,0);
  set<ll> a;
  ll ans = 0;
  rep(i,n){
    ll m;cin>>m;
    if(m>n){ans++;continue;}
    p[m]++;
    a.insert(m);
  }
 

  for(ll num:a){
    //cout<<num<<endl;
    if(p[num]<num)ans += p[num];
    if(p[num]>num)ans += p[num]-num;
  }
  cout<<ans<<endl;
  return 0;
}