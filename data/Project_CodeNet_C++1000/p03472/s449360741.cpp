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
  int n;cin>>n;
  ll h;cin>>h;
  vector<ll> a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int ok = 1;
  ll ans =0,dmg=0;
  int i = 0;
  while(ok){
    if(a[0]<b[i]){
      dmg += b[i];
      ans++;i++;
    }
    else if(i>=n||a[0]>=b[i]){
      ok = 0;
      if((h-dmg)%a[0]==0)ans += (h-dmg)/a[0];
      else ans += (h-dmg)/a[0]+1;
    }
    if(dmg>=h)ok = 0;
    //cout<<dmg<<endl;
  }
  cout<<ans<<endl;
  return 0;
}