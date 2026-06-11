#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
 
const double PI = 3.14159265358979323846;
/*Graph t;
void dfs(int v, int pv=-1){
    for(int vn: t[v]){
        if (vn == pv) continue;
        dfs(vn, v);
    }
}*/
int main() {
  ll n,k;
  cin >> n >> k;
  ll a[n];
  rep(i,n)cin >> a[i];
  ll ans=1000000000000;
  rep(i,n-k+1){
    ll b=a[i],c=a[i+k-1];
    if(b*c>=0)ans=min(ans,max(abs(b),abs(c)));
    else ans=min(ans,abs(b-c)+min(abs(b),abs(c)));
  }
  cout << ans << endl;
}
