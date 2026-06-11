#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
int main(void){
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    ll x=lcm(n,m);
    map<ll,ll> mm;
    ll a=x/n,b=x/m;
    for(ll i=0;i<n;i++){
        ll z=s[i]-'a'+1;
        mm[i*a]=z;
    }
    for(ll i=0;i<m;i++){
        ll z=t[i]-'a'+1;
        if(mm[i*b]>0&&mm[i*b]!=z){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<x<<endl;
}