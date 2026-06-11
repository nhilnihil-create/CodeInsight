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
  vl a(n);
  rep(i,n)cin>>a[i];
  bool ok=true;
  if(a[0]!=0)ok=false;
  rep(i,n-1){
    if(a[i+1]>a[i]&&a[i+1]!=a[i]+1)ok=false;
  }
  if(ok==false){
    cout<<-1<<endl;
    return 0;
  }
  ll ans=0;
  rep(i,n-1){
    if(a[i+1]-a[i]==1)ans++;
    else {
      ans+=a[i+1];
    }
  }
  cout<<ans<<endl;
}
  