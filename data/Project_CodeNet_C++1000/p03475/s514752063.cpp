#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
ll MM = 1000000000; ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

using Graph = vector<vector<ll>>;

int main(){
  int n;
  cin>>n;
  vector<int>c(n-1);
  vector<int>s(n-1);
  vector<int>f(n-1);
  rep(i,n)cin>>c[i]>>s[i]>>f[i];

  vector<ll>ans(n);
  rep(i,n-1){
    ans[i]=s[i]+c[i];
    
    Rep(j,i+1,n-1){
      if(ans[i]<=s[j])ans[i]=s[j];
      else{
	ll tmp=(ans[i]-s[j])/f[j];
	if((ans[i]-s[j])%f[j]==0)ans[i]=s[j]+tmp*f[j];
	else ans[i]=s[j]+(tmp+1)*f[j];
      }
      ans[i]=ans[i]+c[j];
    }

  }
  rep(i,n)cout<<ans[i]<<endl;
  return 0;
}
