#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
int main(){
  int n;cin>>n;
  multiset<ll,greater<ll>> a;
  for(int i=0;i<n;i++){
    ll m;cin>>m;
    a.insert(m);
    }
  vector<ll> p2;
  for(int i=0;i<32;i++)p2.push_back((1ll<<i));
  ll ans=0;
  while(!a.empty()){
    ll t=*a.begin();
    a.erase(a.begin());
    for(int i=31;i>=0;i--){
      ll tmp=p2[i]-t;
      if(tmp<0)break;
      auto ite=a.find(tmp);
      if(ite!=a.end()){
        a.erase(ite);
        ans++;
        break;
        }
        }
        }
        cout<<ans<<endl;
}
